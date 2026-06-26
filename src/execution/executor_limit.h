#pragma once

#include "executor_abstract.h"

class LimitExecutor : public AbstractExecutor {
   private:
    // 子执行器。LimitExecutor 不自己产生记录，也不修改记录内容，
    // 它只是限制最多从 prev_ 往上层交付多少条记录。
    std::unique_ptr<AbstractExecutor> prev_;

    // SQL 中 LIMIT 后面的数字，例如 LIMIT 10。
    int limit_;

    // 已经向上层“放行”了多少条记录。
    // beginTuple 时清零；每次 nextTuple 表示上层消费完当前记录，准备下一条，于是 produced_++。
    int produced_;

   public:
    LimitExecutor(std::unique_ptr<AbstractExecutor> prev, int limit) {
        prev_ = std::move(prev);
        limit_ = limit;
        produced_ = 0;
    }

    void beginTuple() override {
        // 每次重新开始执行时，已输出条数归零，并启动子执行器。
        produced_ = 0;
        prev_->beginTuple();
    }

    void nextTuple() override {
        // 上层调用 nextTuple 表示当前这条记录已经被消费。
        // LimitExecutor 先记录已经输出一条，再让子执行器移动到下一条。
        produced_++;
        prev_->nextTuple();
    }

    // 结束条件有两个：
    // 1. 已经输出了 limit_ 条；
    // 2. 子执行器本身没有更多记录。
    bool is_end() const override { return produced_ >= limit_ || prev_->is_end(); }

    // Limit 不改变 tuple 的格式，所以这些元信息全部透传子执行器。
    size_t tupleLen() const override { return prev_->tupleLen(); }
    const std::vector<ColMeta> &cols() const override { return prev_->cols(); }
    std::string getType() override { return "LimitExecutor"; }
    ColMeta get_col_offset(const TabCol &target) override { return prev_->get_col_offset(target); }
    Rid &rid() override { return _abstract_rid; }

    // 返回当前子执行器指向的记录。
    // LIMIT 只负责控制能不能继续输出，不负责拷贝或改写记录内容。
    std::unique_ptr<RmRecord> Next() override { return prev_->Next(); }
};
