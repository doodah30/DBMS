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

#include "execution_defs.h"
#include "execution_manager.h"
#include "executor_abstract.h"
#include "index/ix.h"
#include "system/sm.h"

class NestedLoopJoinExecutor : public AbstractExecutor {
   private:
    std::unique_ptr<AbstractExecutor> left_;    // 左儿子节点（需要join的表）
    std::unique_ptr<AbstractExecutor> right_;   // 右儿子节点（需要join的表）

    // join 后的输出记录是：左记录 raw bytes + 右记录 raw bytes。
    // 所以输出长度等于左右 tupleLen 之和，输出列也是左列 + 右列。
    size_t len_;                                // join后获得的每条记录的长度
    std::vector<ColMeta> cols_;                 // join后获得的记录的字段

    std::vector<Condition> fed_conds_;          // join条件
    bool isend;

    // 当前实现虽然类名仍叫 NestedLoopJoinExecutor，
    // 但内部已经是 Block Nested-Loop Join：
    // 一次缓存左侧的一批记录到 left_block_，再扫描右侧记录进行匹配。
    std::vector<std::unique_ptr<RmRecord>> left_block_;
    size_t left_block_pos_ = 0;

    // 当前正在和 left_block_ 中记录匹配的右侧记录。
    std::unique_ptr<RmRecord> right_rec_;

    // 当前已经找到、准备交给上层的 join 结果。
    std::unique_ptr<RmRecord> current_join_rec_;

    // 左侧 join buffer 大小。这里用 64MB，避免把左表全部读入内存。
    // load_left_block 每次最多缓存这么多左侧记录。
    static constexpr size_t JOIN_BUFFER_SIZE = 64 * 1024 * 1024;

    bool load_left_block() {
        // 载入下一块左侧记录。
        //
        // 普通 NLJ 是“一条左记录扫描一遍右表”；
        // BNLJ 是“一块左记录扫描一遍右表”。
        // 这个函数就是负责构造“一块左记录”。
        left_block_.clear();
        left_block_pos_ = 0;
        size_t used = 0;
        size_t left_tuple_len = left_->tupleLen();

        // left_block_.empty() 这个条件保证即使单条记录长度超过 JOIN_BUFFER_SIZE，
        // 也至少能装入一条，避免死循环。
        while (!left_->is_end() && (left_block_.empty() || used + left_tuple_len <= JOIN_BUFFER_SIZE)) {
            auto rec = left_->Next();
            // 拷贝左记录，而不是保存指针。
            // 这样 left_ 后续移动到下一条记录时，left_block_ 中的数据仍然有效。
            left_block_.push_back(std::make_unique<RmRecord>(*rec));
            used += left_tuple_len;
            left_->nextTuple();
        }
        return !left_block_.empty();
    }

    std::unique_ptr<RmRecord> make_join_record(const RmRecord *left_rec, const RmRecord *right_rec) const {
        // 拼接左右记录：
        // [left tuple bytes][right tuple bytes]
        //
        // 注意构造函数中已经把右表字段的 offset 整体加上 left_->tupleLen()，
        // 所以上层用 cols_ 解释 joined record 时能找到正确字段。
        auto rec = std::make_unique<RmRecord>(len_);
        memcpy(rec->data, left_rec->data, left_->tupleLen());
        memcpy(rec->data + left_->tupleLen(), right_rec->data, right_->tupleLen());
        return rec;
    }

    void find_next_match() {
        // 从当前状态继续找下一条满足 join 条件的结果。
        //
        // 状态包括：
        // - 当前 left_block_
        // - 当前 right_rec_
        // - 当前 left_block_pos_
        //
        // 找到一条匹配后立刻 return，让上层 Next() 可以取走 current_join_rec_。
        current_join_rec_ = nullptr;
        while (!left_block_.empty()) {
            while (!right_->is_end()) {
                if (right_rec_ == nullptr) {
                    // 取一条右侧记录，让它和当前左块中的所有记录逐一拼接尝试。
                    right_rec_ = right_->Next();
                    left_block_pos_ = 0;
                }
                while (left_block_pos_ < left_block_.size()) {
                    auto joined = make_join_record(left_block_[left_block_pos_].get(), right_rec_.get());
                    left_block_pos_++;
                    // join 条件统一用 eval_conds 判断。
                    // 因此不仅支持等值连接，也支持 <、>、<=、>= 等非等值连接。
                    if (eval_conds(cols_, joined.get(), fed_conds_)) {
                        current_join_rec_ = std::move(joined);
                        return;
                    }
                }
                // 当前右记录已经和整个左块匹配完，移动到下一条右记录。
                right_->nextTuple();
                right_rec_ = nullptr;
            }

            // 当前左块已经和整个右输入匹配完。
            // 加载下一块左记录，并把右输入重新从头开始扫描。
            if (!load_left_block()) {
                break;
            }
            right_->beginTuple();
            right_rec_ = nullptr;
        }
        isend = true;
    }

   public:
    NestedLoopJoinExecutor(std::unique_ptr<AbstractExecutor> left, std::unique_ptr<AbstractExecutor> right, 
                            std::vector<Condition> conds) {
        left_ = std::move(left);
        right_ = std::move(right);
        len_ = left_->tupleLen() + right_->tupleLen();
        cols_ = left_->cols();
        auto right_cols = right_->cols();
        for (auto &col : right_cols) {
            // 右侧字段在 joined record 中排在左侧字段后面，
            // 所以右侧字段 offset 要整体后移左 tuple 的长度。
            col.offset += left_->tupleLen();
        }

        cols_.insert(cols_.end(), right_cols.begin(), right_cols.end());
        isend = false;
        fed_conds_ = std::move(conds);

    }

    void beginTuple() override {
        // 初始化左右子执行器，加载第一块左记录，然后找到第一条匹配结果。
        isend = false;
        left_->beginTuple();
        right_->beginTuple();
        right_rec_ = nullptr;
        current_join_rec_ = nullptr;
        if (!load_left_block()) {
            isend = true;
            return;
        }
        find_next_match();
    }

    void nextTuple() override {
        // 上层消费掉当前 join 结果后，继续寻找下一条匹配。
        if (isend) {
            return;
        }
        find_next_match();
    }

    std::unique_ptr<RmRecord> Next() override {
        // 返回当前匹配结果的拷贝。
        return std::make_unique<RmRecord>(*current_join_rec_);
    }

    bool is_end() const override { return isend; }
    size_t tupleLen() const override { return len_; }
    const std::vector<ColMeta> &cols() const override { return cols_; }
    std::string getType() override { return "NestedLoopJoinExecutor"; }
    ColMeta get_col_offset(const TabCol &target) override { return *get_col(cols_, target); }
    Rid &rid() override { return _abstract_rid; }
};
