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
#include <fstream>
#include "execution_defs.h"
#include "execution_manager.h"
#include "executor_abstract.h"
#include "index/ix.h"
#include "system/sm.h"

class UpdateExecutor : public AbstractExecutor {
   private:
    TabMeta tab_;
    std::vector<Condition> conds_;
    RmFileHandle *fh_;
    std::vector<Rid> rids_;
    std::string tab_name_;
    std::vector<SetClause> set_clauses_;
    SmManager *sm_manager_;

   public:
    UpdateExecutor(SmManager *sm_manager, const std::string &tab_name, std::vector<SetClause> set_clauses,
                   std::vector<Condition> conds, std::vector<Rid> rids, Context *context) {
        sm_manager_ = sm_manager;
        tab_name_ = tab_name;
        set_clauses_ = set_clauses;
        tab_ = sm_manager_->db_.get_table(tab_name);
        fh_ = sm_manager_->fhs_.at(tab_name).get();
        conds_ = conds;
        rids_ = rids;
        context_ = context;
    }
    std::unique_ptr<RmRecord> Next() override {
        if (context_ != nullptr && context_->lock_mgr_ != nullptr && context_->txn_ != nullptr &&
            context_->txn_->get_isolation_level() == IsolationLevel::SERIALIZABLE &&
            !context_->lock_mgr_->lock_exclusive_on_table(context_->txn_, fh_->GetFd())) {
            throw TransactionAbortException(context_->txn_->get_transaction_id(), AbortReason::DEADLOCK_PREVENTION);
        }

        std::vector<std::unique_ptr<RmRecord>> new_records;
        new_records.reserve(rids_.size());
        for (auto &rid : rids_) {
            if (context_ != nullptr && context_->lock_mgr_ != nullptr && context_->txn_ != nullptr &&
                !context_->lock_mgr_->lock_exclusive_on_record(context_->txn_, rid, fh_->GetFd())) {
                throw TransactionAbortException(context_->txn_->get_transaction_id(), AbortReason::DEADLOCK_PREVENTION);
            }
            std::unique_ptr<RmRecord> rec;
            try {
                // 1. 先读取旧记录，再拷贝出一份 new_rec。
                // update 不是重建整张表，而是在旧记录副本上覆盖 set 子句涉及的字段。
                rec = fh_->get_record(rid, context_);
            } catch (RecordNotFoundError &) {
                if (context_ != nullptr && context_->txn_ != nullptr) {
                    throw TransactionAbortException(context_->txn_->get_transaction_id(),
                                                    AbortReason::DEADLOCK_PREVENTION);
                }
                throw;
            }
            auto new_rec = std::make_unique<RmRecord>(*rec);
            for (auto &set_clause : set_clauses_) {
                auto col = tab_.get_col(set_clause.lhs.col_name);
                if (col->type != set_clause.rhs.type) {
                    throw IncompatibleTypeError(coltype2str(col->type), coltype2str(set_clause.rhs.type));
                }
                if (set_clause.rhs.raw == nullptr) {
                    const_cast<Value &>(set_clause.rhs).init_raw(col->len);
                }
                memcpy(new_rec->data + col->offset, set_clause.rhs.raw->data, col->len);
            }
            new_records.push_back(std::move(new_rec));
        }

        // 2. 更新前先检查所有新记录的索引 key 是否会违反唯一性。
        //
        // 为什么要在真正修改表/索引前统一检查？
        // 因为如果更新到一半才发现 Duplicate key，前面已经改过的记录和索引就难回滚。
        //
        // 注意 existing != rids_[rec_idx]：
        // 如果新 key 和自己旧 key 一样，这是允许的；只有撞到其他记录的 Rid 才算重复。
        for (size_t rec_idx = 0; rec_idx < new_records.size(); ++rec_idx) {
            for (auto &index : tab_.indexes) {
                auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name_, index.cols)).get();
                std::unique_ptr<char[]> key(new char[index.col_tot_len]);
                int offset = 0;
                for (int i = 0; i < index.col_num; ++i) {
                    memcpy(key.get() + offset, new_records[rec_idx]->data + index.cols[i].offset, index.cols[i].len);
                    offset += index.cols[i].len;
                }
                std::vector<Rid> result;
                if (ih->get_value(key.get(), &result, context_->txn_)) {
                    for (auto &existing : result) {
                        if (existing != rids_[rec_idx]) {
                            throw RMDBError("Duplicate key");
                        }
                    }
                }
            }
        }

        for (size_t rec_idx = 0; rec_idx < rids_.size(); ++rec_idx) {
            std::unique_ptr<RmRecord> old_rec;
            try {
                // 3. 真正执行更新前，再读一次旧记录。
                // 后面删除旧索引 key、写日志/回滚信息都需要旧记录内容。
                old_rec = fh_->get_record(rids_[rec_idx], context_);
            } catch (RecordNotFoundError &) {
                if (context_ != nullptr && context_->txn_ != nullptr) {
                    throw TransactionAbortException(context_->txn_->get_transaction_id(),
                                                    AbortReason::DEADLOCK_PREVENTION);
                }
                throw;
            }
            if (context_ != nullptr && context_->txn_ != nullptr) {
                if (context_->log_mgr_ != nullptr) {
                    UpdateLogRecord log_record(context_->txn_->get_transaction_id(), *old_rec, *new_records[rec_idx],
                                               rids_[rec_idx], tab_name_);
                    log_record.prev_lsn_ = context_->txn_->get_prev_lsn();
                    lsn_t lsn = context_->log_mgr_->add_log_to_buffer(&log_record);
                    context_->txn_->set_prev_lsn(lsn);
                }
                context_->txn_->append_write_record(
                    new WriteRecord(WType::UPDATE_TUPLE, tab_name_, rids_[rec_idx], *old_rec));
                context_->txn_->upsert_snapshot_record(tab_name_, rids_[rec_idx], *new_records[rec_idx]);
            }

            // 4. 同步维护所有索引。
            //
            // update 对索引来说等价于：
            //   删除旧 key -> Rid
            //   插入新 key -> 同一个 Rid
            //
            // 即使 set 子句没有改到某个索引列，old_key 和 new_key 可能相同；
            // 当前实现仍然统一 delete + insert，逻辑简单，能保持索引和表记录一致。
            for (auto &index : tab_.indexes) {
                auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name_, index.cols)).get();
                std::unique_ptr<char[]> old_key(new char[index.col_tot_len]);
                std::unique_ptr<char[]> new_key(new char[index.col_tot_len]);
                int offset = 0;
                for (int i = 0; i < index.col_num; ++i) {
                    memcpy(old_key.get() + offset, old_rec->data + index.cols[i].offset, index.cols[i].len);
                    memcpy(new_key.get() + offset, new_records[rec_idx]->data + index.cols[i].offset, index.cols[i].len);
                    offset += index.cols[i].len;
                }
                ih->delete_entry(old_key.get(), context_->txn_);
                ih->insert_entry(new_key.get(), rids_[rec_idx], context_->txn_);
            }

            // 5. 索引维护完成后，把新记录写回表文件原 Rid 位置。
            fh_->update_record(rids_[rec_idx], new_records[rec_idx]->data, context_);
        }
        return nullptr;
    }

    Rid &rid() override { return _abstract_rid; }
};
