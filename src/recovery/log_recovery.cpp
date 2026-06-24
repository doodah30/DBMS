/* Copyright (c) 2023 Renmin University of China
RMDB is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
        http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "log_recovery.h"

#include "index/ix.h"
#include "record/rm_scan.h"

namespace {
std::unique_ptr<LogRecord> deserialize_log_record(const char *data, int remaining) {
    if (remaining < LOG_HEADER_SIZE) {
        return nullptr;
    }
    LogType type = *reinterpret_cast<const LogType *>(data + OFFSET_LOG_TYPE);
    uint32_t len = *reinterpret_cast<const uint32_t *>(data + OFFSET_LOG_TOT_LEN);
    if (len < LOG_HEADER_SIZE || static_cast<int>(len) > remaining) {
        return nullptr;
    }

    std::unique_ptr<LogRecord> record;
    switch (type) {
        case LogType::begin:
            record = std::make_unique<BeginLogRecord>();
            break;
        case LogType::commit:
            record = std::make_unique<CommitLogRecord>();
            break;
        case LogType::ABORT:
            record = std::make_unique<AbortLogRecord>();
            break;
        case LogType::INSERT:
            record = std::make_unique<InsertLogRecord>();
            break;
        case LogType::DELETE:
            record = std::make_unique<DeleteLogRecord>();
            break;
        case LogType::UPDATE:
            record = std::make_unique<UpdateLogRecord>();
            break;
        default:
            return nullptr;
    }
    record->deserialize(data);
    return record;
}

std::unique_ptr<char[]> build_index_key(const IndexMeta &index, const RmRecord &record) {
    auto key = std::make_unique<char[]>(index.col_tot_len);
    int offset = 0;
    for (auto &col : index.cols) {
        memcpy(key.get() + offset, record.data + col.offset, col.len);
        offset += col.len;
    }
    return key;
}
}

/**
 * @description: analyze阶段，需要获得脏页表（DPT）和未完成的事务列表（ATT）
 */
void RecoveryManager::analyze() {
    logs_.clear();
    committed_txns_.clear();
    aborted_txns_.clear();

    int offset = 0;
    while (true) {
        int bytes = disk_manager_->read_log(buffer_.buffer_, LOG_BUFFER_SIZE, offset);
        if (bytes <= 0) {
            break;
        }
        int local = 0;
        while (local < bytes) {
            auto record = deserialize_log_record(buffer_.buffer_ + local, bytes - local);
            if (record == nullptr) {
                return;
            }
            local += record->log_tot_len_;
            if (record->log_type_ == LogType::commit) {
                committed_txns_.insert(record->log_tid_);
            } else if (record->log_type_ == LogType::ABORT) {
                aborted_txns_.insert(record->log_tid_);
            }
            logs_.push_back(std::move(record));
        }
        offset += bytes;
    }
}

/**
 * @description: 重做所有未落盘的操作
 */
void RecoveryManager::redo() {
    auto insert_indexes = [&](const std::string &tab_name, const RmRecord &record, const Rid &rid) {
        TabMeta &tab = sm_manager_->db_.get_table(tab_name);
        for (auto &index : tab.indexes) {
            auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name, index.cols)).get();
            auto key = build_index_key(index, record);
            std::vector<Rid> found;
            if (!ih->get_value(key.get(), &found, nullptr)) {
                ih->insert_entry(key.get(), rid, nullptr);
            }
        }
    };
    auto delete_indexes = [&](const std::string &tab_name, const RmRecord &record) {
        TabMeta &tab = sm_manager_->db_.get_table(tab_name);
        for (auto &index : tab.indexes) {
            auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name, index.cols)).get();
            auto key = build_index_key(index, record);
            ih->delete_entry(key.get(), nullptr);
        }
    };

    for (auto &record : logs_) {
        if (!committed_txns_.count(record->log_tid_)) {
            continue;
        }
        if (record->log_type_ == LogType::INSERT) {
            auto *log = static_cast<InsertLogRecord *>(record.get());
            auto &fh = sm_manager_->fhs_.at(log->table_name());
            try {
                fh->insert_record(log->rid_, log->insert_value_.data);
            } catch (RecordNotFoundError &) {
                fh->update_record(log->rid_, log->insert_value_.data, nullptr);
            }
            insert_indexes(log->table_name(), log->insert_value_, log->rid_);
        } else if (record->log_type_ == LogType::DELETE) {
            auto *log = static_cast<DeleteLogRecord *>(record.get());
            auto &fh = sm_manager_->fhs_.at(log->table_name());
            try {
                delete_indexes(log->table_name(), log->delete_value_);
                fh->delete_record(log->rid_, nullptr);
            } catch (RecordNotFoundError &) {
            }
        } else if (record->log_type_ == LogType::UPDATE) {
            auto *log = static_cast<UpdateLogRecord *>(record.get());
            auto &fh = sm_manager_->fhs_.at(log->table_name());
            try {
                delete_indexes(log->table_name(), log->old_value_);
                fh->update_record(log->rid_, log->new_value_.data, nullptr);
                insert_indexes(log->table_name(), log->new_value_, log->rid_);
            } catch (RecordNotFoundError &) {
                fh->insert_record(log->rid_, log->new_value_.data);
                insert_indexes(log->table_name(), log->new_value_, log->rid_);
            }
        }
    }
}

/**
 * @description: 回滚未完成的事务
 */
void RecoveryManager::undo() {
    auto insert_indexes = [&](const std::string &tab_name, const RmRecord &record, const Rid &rid) {
        TabMeta &tab = sm_manager_->db_.get_table(tab_name);
        for (auto &index : tab.indexes) {
            auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name, index.cols)).get();
            auto key = build_index_key(index, record);
            std::vector<Rid> found;
            if (!ih->get_value(key.get(), &found, nullptr)) {
                ih->insert_entry(key.get(), rid, nullptr);
            }
        }
    };
    auto delete_indexes = [&](const std::string &tab_name, const RmRecord &record) {
        TabMeta &tab = sm_manager_->db_.get_table(tab_name);
        for (auto &index : tab.indexes) {
            auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name, index.cols)).get();
            auto key = build_index_key(index, record);
            ih->delete_entry(key.get(), nullptr);
        }
    };

    for (auto iter = logs_.rbegin(); iter != logs_.rend(); ++iter) {
        auto &record = *iter;
        if (committed_txns_.count(record->log_tid_) || aborted_txns_.count(record->log_tid_)) {
            continue;
        }
        if (record->log_type_ == LogType::INSERT) {
            auto *log = static_cast<InsertLogRecord *>(record.get());
            auto &fh = sm_manager_->fhs_.at(log->table_name());
            try {
                delete_indexes(log->table_name(), log->insert_value_);
                fh->delete_record(log->rid_, nullptr);
            } catch (RecordNotFoundError &) {
            }
        } else if (record->log_type_ == LogType::DELETE) {
            auto *log = static_cast<DeleteLogRecord *>(record.get());
            auto &fh = sm_manager_->fhs_.at(log->table_name());
            try {
                fh->insert_record(log->rid_, log->delete_value_.data);
            } catch (RecordNotFoundError &) {
                fh->update_record(log->rid_, log->delete_value_.data, nullptr);
            }
            insert_indexes(log->table_name(), log->delete_value_, log->rid_);
        } else if (record->log_type_ == LogType::UPDATE) {
            auto *log = static_cast<UpdateLogRecord *>(record.get());
            auto &fh = sm_manager_->fhs_.at(log->table_name());
            try {
                delete_indexes(log->table_name(), log->new_value_);
                fh->update_record(log->rid_, log->old_value_.data, nullptr);
            } catch (RecordNotFoundError &) {
                fh->insert_record(log->rid_, log->old_value_.data);
            }
            insert_indexes(log->table_name(), log->old_value_, log->rid_);
        }
    }

    for (auto &entry : sm_manager_->fhs_) {
        entry.second->flush();
    }
    for (auto &entry : sm_manager_->ihs_) {
        entry.second->flush();
    }
}
