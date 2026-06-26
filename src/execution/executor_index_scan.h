/* Copyright (c) 2023 Renmin University of China
RMDB is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
        http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#pragma once

#include <optional>

#include "execution_defs.h"
#include "execution_manager.h"
#include "executor_abstract.h"
#include "index/ix.h"
#include "record/rm_scan.h"
#include "system/sm.h"

class IndexScanExecutor : public AbstractExecutor {
   private:
    std::string tab_name_;                      // 表名称
    std::string visible_name_;
    TabMeta tab_;                               // 表的元数据
    std::vector<Condition> conds_;              // 扫描条件
    RmFileHandle *fh_;                          // 表的数据文件句柄
    std::vector<ColMeta> cols_;                 // 需要读取的字段
    size_t len_;                                // 选取出来的一条记录的长度
    std::vector<Condition> fed_conds_;          // 扫描条件，和conds_字段相同

    std::vector<std::string> index_col_names_;  // index scan涉及到的索引包含的字段
    IndexMeta index_meta_;                      // index scan涉及到的索引元数据

    Rid rid_;
    std::unique_ptr<RecScan> scan_;
    std::vector<Rid> matched_rids_;
    size_t cursor_ = 0;
    bool use_snapshot_ = false;
    Transaction::SnapshotRecords snapshot_records_;
    size_t snapshot_cursor_ = 0;

    SmManager *sm_manager_;

    struct IndexKeyCondition {
        int key_offset;
        ColMeta col;
        Condition cond;
    };

    std::optional<Condition> find_value_cond(const ColMeta &index_col, CompOp op) const {
        // 在当前扫描条件中，寻找“索引列 op 常量”的条件。
        // 注意这里按索引列名找，而不是按 SQL where 条件书写顺序找。
        // 例如索引 (id, name)，where name='a' and id=1 仍然能找到 id 条件。
        auto cond_it = std::find_if(fed_conds_.begin(), fed_conds_.end(), [&](const Condition &cond) {
            return cond.is_rhs_val && cond.op == op && cond.lhs_col.tab_name == visible_name_ &&
                   cond.lhs_col.col_name == index_col.name;
        });
        if (cond_it == fed_conds_.end()) {
            return std::nullopt;
        }
        return *cond_it;
    }

    std::vector<IndexKeyCondition> build_index_key_conds() const {
        // 为范围/前缀扫描准备条件。
        //
        // 如果不能拼出完整等值 key，就退而求其次，收集索引左前缀上的可用条件：
        // - 等值条件可以继续向后匹配下一列；
        // - 范围条件可以用于当前列，但遇到范围列后就停止继续扩展。
        //
        // 例如索引 (id, name, score):
        // where id = 1 and name > 'A' and score = 90
        // 能用于索引过滤的是 id = 1、name > 'A'，score 不再用于索引前缀定位。
        std::vector<IndexKeyCondition> key_conds;
        int key_offset = 0;
        for (auto &index_col : index_meta_.cols) {
            auto eq_cond = find_value_cond(index_col, OP_EQ);
            if (eq_cond.has_value()) {
                key_conds.push_back({key_offset, index_col, *eq_cond});
                key_offset += index_col.len;
                continue;
            }

            for (auto op : {OP_LT, OP_LE, OP_GT, OP_GE}) {
                auto range_cond = find_value_cond(index_col, op);
                if (range_cond.has_value()) {
                    key_conds.push_back({key_offset, index_col, *range_cond});
                }
            }
            break;
        }
        return key_conds;
    }

   public:
    IndexScanExecutor(SmManager *sm_manager, std::string tab_name, std::vector<Condition> conds,
                    std::vector<std::string> index_col_names, Context *context, std::string visible_name = "") {
        sm_manager_ = sm_manager;
        context_ = context;
        tab_name_ = std::move(tab_name);
        visible_name_ = visible_name.empty() ? tab_name_ : std::move(visible_name);
        tab_ = sm_manager_->db_.get_table(tab_name_);
        conds_ = std::move(conds);
        // index_no_ = index_no;
        index_col_names_ = index_col_names; 
        index_meta_ = *(tab_.get_index_meta(index_col_names_));
        fh_ = sm_manager_->fhs_.at(tab_name_).get();
        cols_ = tab_.cols;
        for (auto &col : cols_) {
            col.tab_name = visible_name_;
        }
        len_ = cols_.back().offset + cols_.back().len;
        std::map<CompOp, CompOp> swap_op = {
            {OP_EQ, OP_EQ}, {OP_NE, OP_NE}, {OP_LT, OP_GT}, {OP_GT, OP_LT}, {OP_LE, OP_GE}, {OP_GE, OP_LE},
        };

        for (auto &cond : conds_) {
            if (cond.lhs_col.tab_name != visible_name_) {
                // lhs is on other table, now rhs must be on this table
                assert(!cond.is_rhs_val && cond.rhs_col.tab_name == visible_name_);
                // swap lhs and rhs
                std::swap(cond.lhs_col, cond.rhs_col);
                cond.op = swap_op.at(cond.op);
            }
        }
        fed_conds_ = conds_;
    }

    void beginTuple() override {
        if (context_ != nullptr && context_->lock_mgr_ != nullptr && context_->txn_ != nullptr &&
            context_->txn_->get_isolation_level() == IsolationLevel::SERIALIZABLE &&
            !context_->lock_mgr_->lock_shared_on_table(context_->txn_, fh_->GetFd())) {
            throw TransactionAbortException(context_->txn_->get_transaction_id(), AbortReason::DEADLOCK_PREVENTION);
        }

        const auto *snapshot = context_ != nullptr && context_->txn_ != nullptr &&
                                       context_->txn_->get_isolation_level() == IsolationLevel::REPEATABLE_READ
                                   ? context_->txn_->get_snapshot_records(tab_name_)
                                   : nullptr;
        if (context_ != nullptr && context_->txn_ != nullptr &&
            context_->txn_->get_isolation_level() == IsolationLevel::SERIALIZABLE) {
            context_->txn_->set_has_read(true);
        }
        if (snapshot != nullptr) {
            use_snapshot_ = true;
            snapshot_records_ = *snapshot;
            snapshot_cursor_ = 0;
            while (snapshot_cursor_ < snapshot_records_.size()) {
                rid_ = snapshot_records_[snapshot_cursor_].first;
                if (eval_conds(cols_, &snapshot_records_[snapshot_cursor_].second, fed_conds_)) {
                    return;
                }
                snapshot_cursor_++;
            }
            return;
        }
        use_snapshot_ = false;
        matched_rids_.clear();
        cursor_ = 0;
        auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name_, index_meta_.cols)).get();
        std::unique_ptr<char[]> key(new char[index_meta_.col_tot_len]);

        // 1. 先尝试完整等值点查。
        //
        // 对索引 (id, name)，只有 where 中同时有 id = ? 和 name = ?，
        // 才能拼出完整 key：
        //   key = [id raw bytes][name raw bytes]
        //
        // 如果能拼出完整 key，就调用 get_value，直接得到最多一个 Rid。
        bool can_use_exact = true;
        int offset = 0;
        for (auto &index_col : index_meta_.cols) {
            auto cond_it = std::find_if(fed_conds_.begin(), fed_conds_.end(), [&](const Condition &cond) {
                return cond.is_rhs_val && cond.op == OP_EQ && cond.lhs_col.tab_name == visible_name_ &&
                       cond.lhs_col.col_name == index_col.name;
            });
            if (cond_it == fed_conds_.end()) {
                can_use_exact = false;
                break;
            }
            memcpy(key.get() + offset, cond_it->rhs_val.raw->data, index_col.len);
            offset += index_col.len;
        }
        if (can_use_exact) {
            ih->get_value(key.get(), &matched_rids_, context_ == nullptr ? nullptr : context_->txn_);
        } else {
            // 2. 拼不出完整等值 key，就构造范围/前缀条件。
            //
            // 例如索引 (id, name):
            //   where id > 10
            //   where id = 1 and name > 'A'
            //
            // 当前 entries_ 是内存 map；这里通过 predicate 遍历所有索引 key，
            // 在 key 的对应偏移位置取出字段 raw bytes，与 where 右值比较。
            auto key_conds = build_index_key_conds();
            if (key_conds.empty()) {
                // 3. 如果连可用的索引前缀条件都没有，就退化为全索引扫描。
                // 拿到所有 Rid 后，下面仍会用 eval_conds 做完整 where 过滤。
                ih->get_all_rids(&matched_rids_);
            } else {
                ih->get_rids_by_key_predicate([&](const char *index_key) {
                    for (auto &key_cond : key_conds) {
                        int cmp = ix_compare(index_key + key_cond.key_offset,
                                             key_cond.cond.rhs_val.raw->data,
                                             key_cond.col.type, key_cond.col.len);
                        if (!compare_result(cmp, key_cond.cond.op)) {
                            return false;
                        }
                    }
                    return true;
                }, &matched_rids_);
            }
        }

        // 4. 索引只负责提供候选 Rid。
        // 候选记录仍然必须回表读取真实记录，并用完整 where 条件 eval_conds 再过滤一遍。
        // 这样即使索引过滤只用了部分条件，也不会输出不满足 where 的记录。
        while (cursor_ < matched_rids_.size()) {
            rid_ = matched_rids_[cursor_];
            auto rec = fh_->get_record(rid_, context_);
            if (eval_conds(cols_, rec.get(), fed_conds_)) {
                return;
            }
            cursor_++;
        }
    }

    void nextTuple() override {
        if (use_snapshot_) {
            if (snapshot_cursor_ < snapshot_records_.size()) {
                snapshot_cursor_++;
            }
            while (snapshot_cursor_ < snapshot_records_.size()) {
                rid_ = snapshot_records_[snapshot_cursor_].first;
                if (eval_conds(cols_, &snapshot_records_[snapshot_cursor_].second, fed_conds_)) {
                    return;
                }
                snapshot_cursor_++;
            }
            return;
        }
        if (cursor_ < matched_rids_.size()) {
            cursor_++;
        }
        while (cursor_ < matched_rids_.size()) {
            rid_ = matched_rids_[cursor_];
            auto rec = fh_->get_record(rid_, context_);
            if (eval_conds(cols_, rec.get(), fed_conds_)) {
                return;
            }
            cursor_++;
        }
    }

    std::unique_ptr<RmRecord> Next() override {
        if (use_snapshot_) {
            return std::make_unique<RmRecord>(snapshot_records_[snapshot_cursor_].second);
        }
        return fh_->get_record(rid_, context_);
    }

    bool is_end() const override {
        return use_snapshot_ ? snapshot_cursor_ >= snapshot_records_.size() : cursor_ >= matched_rids_.size();
    }
    size_t tupleLen() const override { return len_; }
    const std::vector<ColMeta> &cols() const override { return cols_; }
    std::string getType() override { return "IndexScanExecutor"; }
    ColMeta get_col_offset(const TabCol &target) override { return *get_col(cols_, target); }
    Rid &rid() override { return rid_; }
};
