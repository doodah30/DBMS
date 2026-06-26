/* Copyright (c) 2023 Renmin University of China
RMDB is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
        http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "sm_manager.h"

#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <set>

#include "index/ix.h"
#include "record/rm.h"
#include "record/rm_scan.h"
#include "record_printer.h"

/**
 * @description: 判断是否为一个文件夹
 * @return {bool} 返回是否为一个文件夹
 * @param {string&} db_name 数据库文件名称，与文件夹同名
 */
bool SmManager::is_dir(const std::string& db_name) {
    struct stat st;
    return stat(db_name.c_str(), &st) == 0 && S_ISDIR(st.st_mode);
}

/**
 * @description: 创建数据库，所有的数据库相关文件都放在数据库同名文件夹下
 * @param {string&} db_name 数据库名称
 */
void SmManager::create_db(const std::string& db_name) {
    if (is_dir(db_name)) {
        throw DatabaseExistsError(db_name);
    }
    //为数据库创建一个子目录
    std::string cmd = "mkdir " + db_name;
    if (system(cmd.c_str()) < 0) {  // 创建一个名为db_name的目录
        throw UnixError();
    }
    if (chdir(db_name.c_str()) < 0) {  // 进入名为db_name的目录
        throw UnixError();
    }
    //创建系统目录
    DbMeta *new_db = new DbMeta();
    new_db->name_ = db_name;

    // 注意，此处ofstream会在当前目录创建(如果没有此文件先创建)和打开一个名为DB_META_NAME的文件
    std::ofstream ofs(DB_META_NAME);

    // 将new_db中的信息，按照定义好的operator<<操作符，写入到ofs打开的DB_META_NAME文件中
    ofs << *new_db;  // 注意：此处重载了操作符<<

    delete new_db;

    // 创建日志文件
    disk_manager_->create_file(LOG_FILE_NAME);

    // 回到根目录
    if (chdir("..") < 0) {
        throw UnixError();
    }
}

/**
 * @description: 删除数据库，同时需要清空相关文件以及数据库同名文件夹
 * @param {string&} db_name 数据库名称，与文件夹同名
 */
void SmManager::drop_db(const std::string& db_name) {
    if (!is_dir(db_name)) {
        throw DatabaseNotFoundError(db_name);
    }
    std::string cmd = "rm -r " + db_name;
    if (system(cmd.c_str()) < 0) {
        throw UnixError();
    }
}

/**
 * @description: 打开数据库，找到数据库对应的文件夹，并加载数据库元数据和相关文件
 * @param {string&} db_name 数据库名称，与文件夹同名
 */
void SmManager::open_db(const std::string& db_name) {
    // 1. 数据库在文件系统里就是一个同名目录；打开数据库前先确认目录存在。
    if (!is_dir(db_name)) {
        throw DatabaseNotFoundError(db_name);
    }

    // 2. 进入数据库目录。之后打开表文件、索引文件、DB_META 都是在这个目录下进行。
    if (chdir(db_name.c_str()) < 0) {
        throw UnixError();
    }

    // 3. 读取数据库元数据。
    // DB_META_NAME 里保存了 db_，包括有哪些表、每张表有哪些字段、有哪些 IndexMeta。
    std::ifstream ifs(DB_META_NAME);
    ifs >> db_;

    // 4. 打开每张表的数据文件，得到 RmFileHandle，保存到 fhs_。
    // fhs_[表名] 后续会被 SeqScan/Insert/Delete/Update 等执行器使用。
    for (auto &entry : db_.tabs_) {
        fhs_.emplace(entry.first, rm_manager_->open_file(entry.first));

        // 5. 对这张表上的每个索引，打开索引文件，得到 IxIndexHandle。
        //
        // 注意：当前 rmdb-main 的索引查询主要依赖 IxIndexHandle::entries_ 这个内存 map，
        // 而不是完整磁盘 B+ 树页。因此 open_db 时必须扫描表数据，把每个索引的 entries_
        // 重新构建出来。元数据只告诉我们“有哪些索引、索引包含哪些列”，真实 key -> Rid
        // 需要从表记录重新拼。
        for (auto &index : entry.second.indexes) {
            auto ih = ix_manager_->open_index(entry.first, index.cols);
            std::unique_ptr<char[]> key(new char[index.col_tot_len]);

            // 6. 扫描整张表，把已有记录逐条插入内存索引。
            // 对每条记录，根据 IndexMeta::cols 中保存的 ColMeta.offset/len，
            // 从记录 raw bytes 中拷贝索引列并拼成完整 key。
            for (RmScan scan(fhs_.at(entry.first).get()); !scan.is_end(); scan.next()) {
                auto rec = fhs_.at(entry.first)->get_record(scan.rid(), nullptr);
                int offset = 0;
                for (auto &col : index.cols) {
                    memcpy(key.get() + offset, rec->data + col.offset, col.len);
                    offset += col.len;
                }

                // 7. 插入 key -> Rid。
                // 这里的 Rid 就是当前扫描到的记录位置；以后 IndexScanExecutor 查到 key 后，
                // 会根据 Rid 回表读取真实记录。
                ih->insert_entry(key.get(), scan.rid(), nullptr);
            }

            // 8. 把打开后的索引句柄保存到 ihs_。
            // 后续 create/drop/select/insert/delete/update 维护或使用索引时，都从 ihs_ 找句柄。
            ihs_.emplace(ix_manager_->get_index_name(entry.first, index.cols), std::move(ih));
        }
    }
}

/**
 * @description: 把数据库相关的元数据刷入磁盘中
 */
void SmManager::flush_meta() {
    // 默认清空文件
    std::ofstream ofs(DB_META_NAME);
    ofs << db_;
}

/**
 * @description: 关闭数据库并把数据落盘
 */
void SmManager::close_db() {
    for (auto &entry : ihs_) {
        ix_manager_->close_index(entry.second.get());
    }
    ihs_.clear();
    for (auto &entry : fhs_) {
        rm_manager_->close_file(entry.second.get());
    }
    fhs_.clear();
    flush_meta();
    if (chdir("..") < 0) {
        throw UnixError();
    }
}

/**
 * @description: 显示所有的表,通过测试需要将其结果写入到output.txt,详情看题目文档
 * @param {Context*} context 
 */
void SmManager::show_tables(Context* context) {
    std::fstream outfile;
    outfile.open("output.txt", std::ios::out | std::ios::app);
    outfile << "| Tables |\n";
    RecordPrinter printer(1);
    printer.print_separator(context);
    printer.print_record({"Tables"}, context);
    printer.print_separator(context);
    for (auto &entry : db_.tabs_) {
        auto &tab = entry.second;
        printer.print_record({tab.name}, context);
        outfile << "| " << tab.name << " |\n";
    }
    printer.print_separator(context);
    outfile.close();
}

/**
 * @description: 显示表的元数据
 * @param {string&} tab_name 表名称
 * @param {Context*} context 
 */
void SmManager::desc_table(const std::string& tab_name, Context* context) {
    TabMeta &tab = db_.get_table(tab_name);

    std::vector<std::string> captions = {"Field", "Type", "Index"};
    RecordPrinter printer(captions.size());
    // Print header
    printer.print_separator(context);
    printer.print_record(captions, context);
    printer.print_separator(context);
    // Print fields
    for (auto &col : tab.cols) {
        std::vector<std::string> field_info = {col.name, coltype2str(col.type), col.index ? "YES" : "NO"};
        printer.print_record(field_info, context);
    }
    // Print footer
    printer.print_separator(context);
}

void SmManager::show_index(const std::string& tab_name, Context* context) {
    TabMeta &tab = db_.get_table(tab_name);
    std::fstream outfile;
    outfile.open("output.txt", std::ios::out | std::ios::app);
    for (auto &index : tab.indexes) {
        outfile << "| " << tab_name << " | unique | (";
        for (int i = 0; i < index.col_num; ++i) {
            if (i > 0) {
                outfile << ",";
            }
            outfile << index.cols[i].name;
        }
        outfile << ") |\n";
    }
    outfile.close();
}

/**
 * @description: 创建表
 * @param {string&} tab_name 表的名称
 * @param {vector<ColDef>&} col_defs 表的字段
 * @param {Context*} context 
 */
void SmManager::create_table(const std::string& tab_name, const std::vector<ColDef>& col_defs, Context* context) {
    if (db_.is_table(tab_name)) {
        throw TableExistsError(tab_name);
    }
    // Create table meta
    int curr_offset = 0;
    TabMeta tab;
    tab.name = tab_name;
    for (auto &col_def : col_defs) {
        ColMeta col = {.tab_name = tab_name,
                       .name = col_def.name,
                       .type = col_def.type,
                       .len = col_def.len,
                       .offset = curr_offset,
                       .index = false};
        curr_offset += col_def.len;
        tab.cols.push_back(col);
    }
    // Create & open record file
    int record_size = curr_offset;  // record_size就是col meta所占的大小（表的元数据也是以记录的形式进行存储的）
    rm_manager_->create_file(tab_name, record_size);
    db_.tabs_[tab_name] = tab;
    // fhs_[tab_name] = rm_manager_->open_file(tab_name);
    fhs_.emplace(tab_name, rm_manager_->open_file(tab_name));

    flush_meta();
}

/**
 * @description: 删除表
 * @param {string&} tab_name 表的名称
 * @param {Context*} context
 */
void SmManager::drop_table(const std::string& tab_name, Context* context) {
    if (!db_.is_table(tab_name)) {
        throw TableNotFoundError(tab_name);
    }
    auto &tab = db_.get_table(tab_name);
    for (auto &index : tab.indexes) {
        std::string ix_name = ix_manager_->get_index_name(tab_name, index.cols);
        if (ihs_.count(ix_name)) {
            ix_manager_->close_index(ihs_.at(ix_name).get());
            ihs_.erase(ix_name);
        }
        ix_manager_->destroy_index(tab_name, index.cols);
    }
    if (fhs_.count(tab_name)) {
        rm_manager_->close_file(fhs_.at(tab_name).get());
        fhs_.erase(tab_name);
    }
    rm_manager_->destroy_file(tab_name);
    db_.tabs_.erase(tab_name);
    flush_meta();
}

/**
 * @description: 创建索引
 * @param {string&} tab_name 表的名称
 * @param {vector<string>&} col_names 索引包含的字段名称
 * @param {Context*} context
 */
void SmManager::create_index(const std::string& tab_name, const std::vector<std::string>& col_names, Context* context) {
    // 1. 建索引前先做合法性检查：表必须存在，同一组列上不能已经有索引。
    if (!db_.is_table(tab_name)) {
        throw TableNotFoundError(tab_name);
    }
    TabMeta &tab = db_.get_table(tab_name);
    if (tab.is_index(col_names)) {
        throw IndexExistsError(tab_name, col_names);
    }

    // 2. 根据列名找到对应的 ColMeta。
    // IndexMeta 保存的不是简单列名，而是一组 ColMeta，因为后续构造索引 key 时
    // 需要知道每个字段在一条记录中的 offset 和 len。
    std::vector<ColMeta> index_cols;
    int col_tot_len = 0;
    for (auto &col_name : col_names) {
        auto col = tab.get_col(col_name);
        index_cols.push_back(*col);
        col_tot_len += col->len;
    }

    // 3. 当前课程实现把 create index 当作唯一索引处理。
    // 因此建索引前必须扫描已有记录，确认这些记录拼出来的 key 没有重复。
    // key 的构造方式：按照索引列顺序，从记录 raw bytes 中拷贝每个字段的字节并拼接。
    std::set<std::string> seen_keys;
    std::unique_ptr<char[]> key(new char[col_tot_len]);
    for (RmScan scan(fhs_.at(tab_name).get()); !scan.is_end(); scan.next()) {
        auto rec = fhs_.at(tab_name)->get_record(scan.rid(), context);
        int offset = 0;
        for (auto &col : index_cols) {
            memcpy(key.get() + offset, rec->data + col.offset, col.len);
            offset += col.len;
        }
        std::string key_str(key.get(), col_tot_len);
        if (!seen_keys.insert(key_str).second) {
            // 如果已有两条记录的索引 key 相同，就不能建立唯一索引。
            throw RMDBError("Duplicate key");
        }
    }

    // 4. 创建并打开索引文件。
    // 注意：索引文件只是索引的存储载体，真正“这个索引建在哪些列上”的说明
    // 还要写入下面的 IndexMeta。
    ix_manager_->create_index(tab_name, index_cols);
    auto ih = ix_manager_->open_index(tab_name, index_cols);

    // 5. 把表中已有记录全部回填进新索引。
    // 建索引不是只改元数据，还必须为历史数据建立 key -> Rid 映射。
    // 之后 select/update/delete 才能通过索引 key 找到真实记录的位置。
    for (RmScan scan(fhs_.at(tab_name).get()); !scan.is_end(); scan.next()) {
        auto rec = fhs_.at(tab_name)->get_record(scan.rid(), context);
        int offset = 0;
        for (auto &col : index_cols) {
            memcpy(key.get() + offset, rec->data + col.offset, col.len);
            offset += col.len;
        }
        ih->insert_entry(key.get(), scan.rid(), context ? context->txn_ : nullptr);
    }

    // 6. 维护表元数据中的索引说明。
    // IndexMeta 是“索引说明书”：记录索引属于哪张表、包含哪些列、key 总长度是多少。
    // 它会随着 db_ 元数据一起刷入 DB_META_NAME，数据库重启后才能知道表上有哪些索引。
    IndexMeta index_meta;
    index_meta.tab_name = tab_name;//属于哪张表
    index_meta.col_tot_len = col_tot_len;//key 总长度
    index_meta.col_num = static_cast<int>(index_cols.size());//包含多少个字段
    index_meta.cols = index_cols;//字段的元数据
    tab.indexes.push_back(index_meta);

    // 7. 把参与索引的列标记为已建索引。
    // 这个 bool 主要用于 desc table/show 之类的展示和简单判断。
    for (auto &col_name : col_names) {
        tab.get_col(col_name)->index = true;
    }

    // 8. 保存打开的索引句柄，后续 insert/delete/update/select 维护或查询索引时会用到。
    ihs_.emplace(ix_manager_->get_index_name(tab_name, index_cols), std::move(ih));
    flush_meta();
}

/**
 * @description: 删除索引
 * @param {string&} tab_name 表名称
 * @param {vector<string>&} col_names 索引包含的字段名称
 * @param {Context*} context
 */
void SmManager::drop_index(const std::string& tab_name, const std::vector<std::string>& col_names, Context* context) {
    // 1. 删索引前先检查表是否存在，并找到要删除的 IndexMeta。
    // 如果索引不存在，get_index_meta 会抛 IndexNotFoundError。
    if (!db_.is_table(tab_name)) {
        throw TableNotFoundError(tab_name);
    }
    TabMeta &tab = db_.get_table(tab_name);
    auto index_it = tab.get_index_meta(col_names);

    // 2. 先记下这个索引包含哪些列。
    // 因为后面会从 tab.indexes 中 erase 掉 IndexMeta，erase 后就不能再通过 index_it 访问这些列了。
    std::vector<std::string> removed_cols;
    for (auto &col_meta : index_it->cols) {
        removed_cols.push_back(col_meta.name);
    }

    // 3. 如果该索引当前已经打开，先关闭并从 ihs_ 中移除句柄。
    // ihs_ 负责保存运行期打开的索引句柄；destroy_index 负责删除底层索引文件。
    std::string ix_name = ix_manager_->get_index_name(tab_name, col_names);
    if (ihs_.count(ix_name)) {
        ix_manager_->close_index(ihs_.at(ix_name).get());
        ihs_.erase(ix_name);
    }
    ix_manager_->destroy_index(tab_name, col_names);

    // 4. 从表元数据中删除这条索引说明。
    tab.indexes.erase(index_it);

    // 5. 重新计算相关列的 index 标记。
    // 一个列可能同时出现在多个复合索引里，例如 index(a,b) 和 index(a,c)。
    // 删除 index(a,b) 后，a 仍然被 index(a,c) 使用，因此不能简单地把 a.index 设成 false。
    for (auto &col_name : removed_cols) {
        bool still_indexed = false;
        for (auto &index : tab.indexes) {
            for (auto &col_meta : index.cols) {
                if (col_meta.name == col_name) {
                    still_indexed = true;
                    break;
                }
            }
            if (still_indexed) {
                break;
            }
        }
        tab.get_col(col_name)->index = still_indexed;
    }

    // 6. 把删除索引后的元数据落盘，保证数据库重启后不会再认为该索引存在。
    flush_meta();
}

/**
 * @description: 删除索引
 * @param {string&} tab_name 表名称
 * @param {vector<ColMeta>&} 索引包含的字段元数据
 * @param {Context*} context
 */
void SmManager::drop_index(const std::string& tab_name, const std::vector<ColMeta>& cols, Context* context) {
    std::vector<std::string> col_names;
    for (auto &col : cols) {
        col_names.push_back(col.name);
    }
    drop_index(tab_name, col_names, context);
}
