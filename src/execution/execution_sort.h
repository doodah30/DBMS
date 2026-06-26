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
#include <algorithm>
#include "execution_defs.h"
#include "execution_manager.h"
#include "executor_abstract.h"
#include "index/ix.h"
#include "system/sm.h"

class SortExecutor : public AbstractExecutor {
   private:
    // 子执行器。SortExecutor 不直接读表，它排序的是 prev_ 已经产生的结果。
    // prev_ 可以是 SeqScan、IndexScan、Join、Aggregate 等任意执行器。
    std::unique_ptr<AbstractExecutor> prev_;

    // 排序后输出的字段元数据和记录长度。
    // Sort 不改变记录内容，也不改变列布局，所以直接沿用 prev_ 的 cols/tupleLen。
    std::vector<ColMeta> cols_;
    size_t len_;

    // 排序列列表。
    // pair.first  是排序列的 ColMeta，用来知道 offset/type/len；
    // pair.second 表示是否降序：true = DESC，false = ASC。
    std::vector<std::pair<ColMeta, bool>> order_cols_;

    // 内存排序缓冲区。
    // beginTuple 会先把 prev_ 的所有结果读入 tuples_，再 std::sort。
    // 这是课程实现里的内存排序，不是成熟数据库的外部排序。
    std::vector<std::unique_ptr<RmRecord>> tuples_;
    size_t cursor_;

   public:
    // 兼容旧接口：只按一个列排序。
    SortExecutor(std::unique_ptr<AbstractExecutor> prev, TabCol sel_cols, bool is_desc) {
        prev_ = std::move(prev);
        cols_ = prev_->cols();
        len_ = prev_->tupleLen();
        order_cols_.push_back({prev_->get_col_offset(sel_cols), is_desc});
        cursor_ = 0;
    }

    // 当前主要使用的构造函数：支持多个 ORDER BY 字段。
    //
    // Planner/Analyze 传入的是 TabCol，例如 (orders, amount)；
    // SortExecutor 需要把它转换成 prev_ 输出记录中的 ColMeta，
    // 这样比较时才能通过 offset 找到对应字段的 raw bytes。
    SortExecutor(std::unique_ptr<AbstractExecutor> prev, const std::vector<std::pair<TabCol, bool>> &order_cols) {
        prev_ = std::move(prev);
        cols_ = prev_->cols();
        len_ = prev_->tupleLen();
        for (auto &order_col : order_cols) {
            order_cols_.push_back({prev_->get_col_offset(order_col.first), order_col.second});
        }
        cursor_ = 0;
    }

    void beginTuple() override { 
        // Sort 是阻塞算子：必须先读完全部输入，才能知道全局排序结果。
        //
        // 例如 ORDER BY amount LIMIT 2，不能先拿两条再排序；
        // 必须先把所有候选结果排序，再让上层 LimitExecutor 取前两条。
        tuples_.clear();
        for (prev_->beginTuple(); !prev_->is_end(); prev_->nextTuple()) {
            tuples_.push_back(prev_->Next());
        }

        // 多列排序比较：
        // 依次比较 order_cols_ 中的每个字段；
        // 如果当前字段相等，就继续比较下一字段；
        // 一旦某字段不同，就根据该字段 ASC/DESC 决定顺序。
        std::sort(tuples_.begin(), tuples_.end(), [&](const auto &lhs, const auto &rhs) {
            for (auto &order_col : order_cols_) {
                const auto &col = order_col.first;
                int cmp = compare_value(lhs->data + col.offset, rhs->data + col.offset, col.type, col.len);
                if (cmp != 0) {
                    // cmp < 0 表示 lhs 当前列小于 rhs 当前列。
                    // ASC:  小的排前面 -> cmp < 0
                    // DESC: 大的排前面 -> cmp > 0
                    return order_col.second ? cmp > 0 : cmp < 0;
                }
            }
            // 所有排序列都相等时，认为 lhs 不小于 rhs。
            // std::sort 不是稳定排序，因此相同 key 的相对顺序不作额外保证。
            return false;
        });
        cursor_ = 0;
    }

    void nextTuple() override {
        if (cursor_ < tuples_.size()) {
            cursor_++;
        }
    }

    std::unique_ptr<RmRecord> Next() override {
        // 返回当前 cursor_ 指向的排序后记录。
        // 这里返回拷贝，避免上层修改 tuples_ 中缓存的记录。
        auto rec = std::make_unique<RmRecord>(len_);
        memcpy(rec->data, tuples_[cursor_]->data, len_);
        return rec;
    }

    bool is_end() const override { return cursor_ >= tuples_.size(); }
    size_t tupleLen() const override { return len_; }
    const std::vector<ColMeta> &cols() const override { return cols_; }
    std::string getType() override { return "SortExecutor"; }
    ColMeta get_col_offset(const TabCol &target) override { return *get_col(cols_, target); }
    Rid &rid() override { return _abstract_rid; }
};
