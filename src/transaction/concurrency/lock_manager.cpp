/* Copyright (c) 2023 Renmin University of China
RMDB is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
        http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "lock_manager.h"

namespace {
bool is_exclusive(LockManager::LockMode mode) {
    return mode == LockManager::LockMode::EXLUCSIVE ||
           mode == LockManager::LockMode::INTENTION_EXCLUSIVE ||
           mode == LockManager::LockMode::S_IX;
}

LockManager::GroupLockMode group_mode_after_grant(LockManager::LockMode mode) {
    switch (mode) {
        case LockManager::LockMode::SHARED:
            return LockManager::GroupLockMode::S;
        case LockManager::LockMode::EXLUCSIVE:
            return LockManager::GroupLockMode::X;
        case LockManager::LockMode::INTENTION_SHARED:
            return LockManager::GroupLockMode::IS;
        case LockManager::LockMode::INTENTION_EXCLUSIVE:
            return LockManager::GroupLockMode::IX;
        case LockManager::LockMode::S_IX:
            return LockManager::GroupLockMode::SIX;
    }
    return LockManager::GroupLockMode::NON_LOCK;
}
}

/**
 * @description: 申请行级共享锁
 * @return {bool} 加锁是否成功
 * @param {Transaction*} txn 要申请锁的事务对象指针
 * @param {Rid&} rid 加锁的目标记录ID 记录所在的表的fd
 * @param {int} tab_fd
 */
bool LockManager::lock_shared_on_record(Transaction* txn, const Rid& rid, int tab_fd) {
    return lock_on_data(txn, LockDataId(tab_fd, rid, LockDataType::RECORD), LockMode::SHARED);
}

/**
 * @description: 申请行级排他锁
 * @return {bool} 加锁是否成功
 * @param {Transaction*} txn 要申请锁的事务对象指针
 * @param {Rid&} rid 加锁的目标记录ID
 * @param {int} tab_fd 记录所在的表的fd
 */
bool LockManager::lock_exclusive_on_record(Transaction* txn, const Rid& rid, int tab_fd) {
    return lock_on_data(txn, LockDataId(tab_fd, rid, LockDataType::RECORD), LockMode::EXLUCSIVE);
}

/**
 * @description: 申请表级读锁
 * @return {bool} 返回加锁是否成功
 * @param {Transaction*} txn 要申请锁的事务对象指针
 * @param {int} tab_fd 目标表的fd
 */
bool LockManager::lock_shared_on_table(Transaction* txn, int tab_fd) {
    return lock_on_data(txn, LockDataId(tab_fd, LockDataType::TABLE), LockMode::SHARED);
}

/**
 * @description: 申请表级写锁
 * @return {bool} 返回加锁是否成功
 * @param {Transaction*} txn 要申请锁的事务对象指针
 * @param {int} tab_fd 目标表的fd
 */
bool LockManager::lock_exclusive_on_table(Transaction* txn, int tab_fd) {
    return lock_on_data(txn, LockDataId(tab_fd, LockDataType::TABLE), LockMode::EXLUCSIVE);
}

/**
 * @description: 申请表级意向读锁
 * @return {bool} 返回加锁是否成功
 * @param {Transaction*} txn 要申请锁的事务对象指针
 * @param {int} tab_fd 目标表的fd
 */
bool LockManager::lock_IS_on_table(Transaction* txn, int tab_fd) {
    return lock_shared_on_table(txn, tab_fd);
}

/**
 * @description: 申请表级意向写锁
 * @return {bool} 返回加锁是否成功
 * @param {Transaction*} txn 要申请锁的事务对象指针
 * @param {int} tab_fd 目标表的fd
 */
bool LockManager::lock_IX_on_table(Transaction* txn, int tab_fd) {
    return lock_exclusive_on_table(txn, tab_fd);
}

/**
 * @description: 释放锁
 * @return {bool} 返回解锁是否成功
 * @param {Transaction*} txn 要释放锁的事务对象指针
 * @param {LockDataId} lock_data_id 要释放的锁ID
 */
bool LockManager::unlock(Transaction* txn, LockDataId lock_data_id) {
    if (txn == nullptr) {
        return true;
    }
    std::lock_guard<std::mutex> lock(latch_);
    auto iter = lock_table_.find(lock_data_id);
    if (iter == lock_table_.end()) {
        return true;
    }
    auto &queue = iter->second.request_queue_;
    queue.remove_if([&](const LockRequest &request) {
        return request.txn_id_ == txn->get_transaction_id();
    });
    txn->get_lock_set()->erase(lock_data_id);
    if (queue.empty()) {
        lock_table_.erase(iter);
    }
    return true;
}

bool LockManager::lock_on_data(Transaction *txn, const LockDataId &lock_data_id, LockMode lock_mode) {
    if (txn == nullptr) {
        return true;
    }
    if (txn->get_state() == TransactionState::SHRINKING) {
        return false;
    }

    std::lock_guard<std::mutex> lock(latch_);
    auto &queue = lock_table_[lock_data_id];
    auto txn_id = txn->get_transaction_id();
    auto self_request = queue.request_queue_.end();

    for (auto iter = queue.request_queue_.begin(); iter != queue.request_queue_.end(); ++iter) {
        if (!iter->granted_) {
            continue;
        }
        if (iter->txn_id_ == txn_id) {
            self_request = iter;
            continue;
        }
        if (lock_mode == LockMode::EXLUCSIVE || is_exclusive(iter->lock_mode_)) {
            return false;
        }
    }

    if (self_request != queue.request_queue_.end()) {
        if (self_request->lock_mode_ == LockMode::EXLUCSIVE || self_request->lock_mode_ == lock_mode) {
            return true;
        }
        self_request->lock_mode_ = lock_mode;
        queue.group_lock_mode_ = group_mode_after_grant(lock_mode);
        return true;
    }

    queue.request_queue_.emplace_back(txn_id, lock_mode);
    queue.request_queue_.back().granted_ = true;
    queue.group_lock_mode_ = group_mode_after_grant(lock_mode);
    txn->get_lock_set()->insert(lock_data_id);
    return true;
}
