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
#include "common/datetime.h"
#include "index/ix.h"
#include "system/sm.h"

class InsertExecutor : public AbstractExecutor {
   private:
    TabMeta tab_;                   // 表的元数据
    std::vector<Value> values_;     // 需要插入的数据
    RmFileHandle *fh_;              // 表的数据文件句柄
    std::string tab_name_;          // 表名称
    Rid rid_;                       // 插入的位置，由于系统默认插入时不指定位置，因此当前rid_在插入后才赋值
    SmManager *sm_manager_;

   public:
    InsertExecutor(SmManager *sm_manager, const std::string &tab_name, std::vector<Value> values, Context *context) {
        sm_manager_ = sm_manager;
        tab_ = sm_manager_->db_.get_table(tab_name);
        values_ = values;
        tab_name_ = tab_name;
        if (values.size() != tab_.cols.size()) {
            throw InvalidValueCountError();
        }
        fh_ = sm_manager_->fhs_.at(tab_name).get();
        context_ = context;
    };

    std::unique_ptr<RmRecord> Next() override {
        if (context_ != nullptr && context_->lock_mgr_ != nullptr && context_->txn_ != nullptr &&
            context_->txn_->get_isolation_level() == IsolationLevel::SERIALIZABLE &&
            !context_->lock_mgr_->lock_exclusive_on_table(context_->txn_, fh_->GetFd())) {
            throw TransactionAbortException(context_->txn_->get_transaction_id(), AbortReason::DEADLOCK_PREVENTION);
        }

        // 1. 先把 SQL values 组装成一条完整的 RmRecord。
        // 每个字段根据 ColMeta.offset 写到记录对应位置，最终得到表文件要插入的 raw bytes。
        RmRecord rec(fh_->get_file_hdr().record_size);
        for (size_t i = 0; i < values_.size(); i++) {
            auto &col = tab_.cols[i];
            auto &val = values_[i];
            if (col.type == TYPE_FLOAT && val.type == TYPE_INT) {
                val.set_float(static_cast<float>(val.int_val));
            } else if (col.type == TYPE_BIGINT && val.type == TYPE_INT) {
                val.set_bigint(static_cast<int64_t>(val.int_val));
            } else if (col.type == TYPE_DATETIME && val.type == TYPE_STRING) {
                val.set_datetime(datetime_util::parse_datetime(val.str_val));
            } else if (col.type != val.type) {
                throw IncompatibleTypeError(coltype2str(col.type), coltype2str(val.type));
            }
            val.init_raw(col.len);
            memcpy(rec.data + col.offset, val.raw->data, col.len);
        }

        // 2. 唯一性检查。
        // 当前索引按唯一索引处理，所以真正插入表记录前，要先检查所有索引的新 key
        // 是否已经存在。这样可以避免“表记录插进去了，但索引发现重复”的半成功状态。
        //
        // 复合索引的 key 是多个索引列 raw bytes 的拼接：
        //   key = [col1 bytes][col2 bytes]...
        // 唯一的是整组 key，不是每个列单独唯一。
        for (auto &index : tab_.indexes) {
            auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name_, index.cols)).get();
            std::unique_ptr<char[]> key(new char[index.col_tot_len]);
            int offset = 0;
            for (int i = 0; i < index.col_num; ++i) {
                memcpy(key.get() + offset, rec.data + index.cols[i].offset, index.cols[i].len);
                offset += index.cols[i].len;
            }
            std::vector<Rid> result;
            if (ih->get_value(key.get(), &result, context_->txn_) && !result.empty()) {
                throw RMDBError("Duplicate key");
            }
        }
        // 3. 唯一性检查通过后，才把记录插入表文件，得到新记录的 Rid。
        rid_ = fh_->insert_record(rec.data, context_);
        if (context_ != nullptr && context_->txn_ != nullptr) {
            if (context_->log_mgr_ != nullptr) {
                InsertLogRecord log_record(context_->txn_->get_transaction_id(), rec, rid_, tab_name_);
                log_record.prev_lsn_ = context_->txn_->get_prev_lsn();
                lsn_t lsn = context_->log_mgr_->add_log_to_buffer(&log_record);
                context_->txn_->set_prev_lsn(lsn);
            }
            context_->txn_->append_write_record(new WriteRecord(WType::INSERT_TUPLE, tab_name_, rid_));
            context_->txn_->upsert_snapshot_record(tab_name_, rid_, rec);
        }
        
        // 4. 表文件插入成功后，同步维护所有索引。
        // 对每个索引重新从新记录 rec 中拼 key，并插入 key -> rid_。
        // 如果不维护索引，后续 select 走索引就找不到这条新记录。
        for(size_t i = 0; i < tab_.indexes.size(); ++i) {
            auto& index = tab_.indexes[i];
            auto ih = sm_manager_->ihs_.at(sm_manager_->get_ix_manager()->get_index_name(tab_name_, index.cols)).get();
            std::unique_ptr<char[]> key(new char[index.col_tot_len]);
            int offset = 0;
            for(size_t i = 0; i < index.col_num; ++i) {
                memcpy(key.get() + offset, rec.data + index.cols[i].offset, index.cols[i].len);
                offset += index.cols[i].len;
            }
            ih->insert_entry(key.get(), rid_, context_->txn_);
        }
        return nullptr;
    }
    Rid &rid() override { return rid_; }
};
