#pragma once

#include <map>
#include <set>
#include <sstream>
#include <cstdint>

#include "common/datetime.h"
#include "executor_abstract.h"

class AggregateExecutor : public AbstractExecutor {
   private:
    // 聚合执行器内部使用的“临时值”。
    // 它既可以表示从输入记录读出来的普通字段值，也可以表示聚合中间状态。
    //
    // 例如：
    //   read_cell(score)       -> Cell(float_val = 95.0)
    //   SUM(score) 中间状态    -> Cell(float_val = 当前累加和)
    //   COUNT(*) 中间状态      -> Cell(int_val = 当前行数)
    //   AVG(score) 中间状态    -> Cell(float_val = 累加和, count = 行数)
    struct Cell {
        ColType type = TYPE_INT;
        int int_val = 0;
        int64_t bigint_val = 0;
        int64_t datetime_val = 0;
        float float_val = 0;
        std::string str_val;
        int count = 0;
        bool initialized = false;
    };

    // 一个分组的状态。
    //
    // group_cells 保存 group by 字段的值，例如 group by course,id 时保存 course 和 id。
    // aggs 保存这个分组里的所有聚合函数状态，例如 MAX(score)、COUNT(*)、SUM(score)。
    struct GroupState {
        std::vector<Cell> group_cells;
        std::map<std::string, Cell> aggs;
    };

    std::unique_ptr<AbstractExecutor> prev_;
    std::vector<std::shared_ptr<ast::SelectItem>> select_items_;
    std::vector<TabCol> group_cols_;
    std::vector<std::shared_ptr<ast::HavingExpr>> having_conds_;
    std::vector<ColMeta> cols_;
    size_t len_;
    std::vector<std::unique_ptr<RmRecord>> tuples_;
    size_t cursor_;

    // 给一个聚合表达式生成唯一名字，用来作为 GroupState::aggs 的 key。
    // 例如：
    //   COUNT(*)        -> "1:*"
    //   SUM(t.score)    -> "4:t.score"
    //
    // 这样 select 里和 having 里引用同一个聚合函数时，可以共用同一份聚合状态。
    std::string agg_key(const std::shared_ptr<ast::SelectItem> &item) const {
        std::string key = std::to_string(static_cast<int>(item->agg_type)) + ":";
        if (item->count_star) {
            return key + "*";
        }
        return key + item->col->tab_name + "." + item->col->col_name;
    }

    // 从一条输入记录 rec 中，按照 ColMeta 的 offset/type 读出一个字段值。
    // 这和普通执行器读取字段的思路一样：记录是 raw bytes，ColMeta 告诉我们从哪里读、按什么类型解释。
    Cell read_cell(const RmRecord *rec, const ColMeta &col) const {
        Cell cell;
        cell.type = col.type;
        cell.initialized = true;
        if (col.type == TYPE_INT) {
            cell.int_val = *reinterpret_cast<int *>(rec->data + col.offset);
        } else if (col.type == TYPE_BIGINT) {
            cell.bigint_val = *reinterpret_cast<int64_t *>(rec->data + col.offset);
        } else if (col.type == TYPE_DATETIME) {
            cell.datetime_val = *reinterpret_cast<int64_t *>(rec->data + col.offset);
        } else if (col.type == TYPE_FLOAT) {
            cell.float_val = *reinterpret_cast<float *>(rec->data + col.offset);
        } else {
            cell.str_val = std::string(rec->data + col.offset, col.len);
            cell.str_val.resize(strlen(cell.str_val.c_str()));
        }
        return cell;
    }

    // 比较两个 Cell，用于 MAX/MIN 和 HAVING 条件判断。
    // 数值类型按数值比，字符串按字典序比，DATETIME/BIGINT 按 int64 比。
    int compare_cell(const Cell &lhs, const Cell &rhs) const {
        if (lhs.type == TYPE_FLOAT || rhs.type == TYPE_FLOAT) {
            float l = lhs.type == TYPE_FLOAT ? lhs.float_val
                      : lhs.type == TYPE_BIGINT ? static_cast<float>(lhs.bigint_val)
                                                 : static_cast<float>(lhs.int_val);
            float r = rhs.type == TYPE_FLOAT ? rhs.float_val
                      : rhs.type == TYPE_BIGINT ? static_cast<float>(rhs.bigint_val)
                                                 : static_cast<float>(rhs.int_val);
            return (l > r) - (l < r);
        }
        if (lhs.type == TYPE_BIGINT || rhs.type == TYPE_BIGINT) {
            int64_t l = lhs.type == TYPE_BIGINT ? lhs.bigint_val : lhs.int_val;
            int64_t r = rhs.type == TYPE_BIGINT ? rhs.bigint_val : rhs.int_val;
            return (l > r) - (l < r);
        }
        if (lhs.type == TYPE_DATETIME || rhs.type == TYPE_DATETIME) {
            int64_t l = lhs.type == TYPE_DATETIME ? lhs.datetime_val : lhs.int_val;
            int64_t r = rhs.type == TYPE_DATETIME ? rhs.datetime_val : rhs.int_val;
            return (l > r) - (l < r);
        }
        if (lhs.type == TYPE_INT) {
            return (lhs.int_val > rhs.int_val) - (lhs.int_val < rhs.int_val);
        }
        return lhs.str_val.compare(rhs.str_val);
    }

    // 把 group by 字段值序列编码成字符串，作为 groups map 的 key。
    //
    // 例如 group by course,id:
    //   ("DB", 1) -> "sDB|i1|"
    //
    // 前缀 i/b/d/f/s 用来区分类型，避免不同类型的文本形式撞在一起。
    std::string group_key(const std::vector<Cell> &cells) const {
        std::ostringstream os;
        for (auto &cell : cells) {
            if (cell.type == TYPE_INT) {
                os << "i" << cell.int_val << "|";
            } else if (cell.type == TYPE_BIGINT) {
                os << "b" << cell.bigint_val << "|";
            } else if (cell.type == TYPE_DATETIME) {
                os << "d" << cell.datetime_val << "|";
            } else if (cell.type == TYPE_FLOAT) {
                os << "f" << cell.float_val << "|";
            } else {
                os << "s" << cell.str_val << "|";
            }
        }
        return os.str();
    }

    // 把 HAVING 右侧常量转换成 Cell，便于和左侧聚合结果比较。
    // 字符串会先尝试按 DATETIME 解析，失败后再当普通字符串处理。
    Cell rhs_cell(const std::shared_ptr<ast::Value> &value) const {
        Cell cell;
        cell.initialized = true;
        if (auto int_lit = std::dynamic_pointer_cast<ast::IntLit>(value)) {
            cell.type = TYPE_INT;
            cell.int_val = int_lit->val;
        } else if (auto bigint_lit = std::dynamic_pointer_cast<ast::BigIntLit>(value)) {
            cell.type = TYPE_BIGINT;
            cell.bigint_val = std::stoll(bigint_lit->val);
        } else if (auto float_lit = std::dynamic_pointer_cast<ast::FloatLit>(value)) {
            cell.type = TYPE_FLOAT;
            cell.float_val = float_lit->val;
        } else if (auto str_lit = std::dynamic_pointer_cast<ast::StringLit>(value)) {
            try {
                cell.type = TYPE_DATETIME;
                cell.datetime_val = datetime_util::parse_datetime(str_lit->val);
            } catch (RMDBError &) {
                cell.type = TYPE_STRING;
                cell.str_val = str_lit->val;
            }
        }
        return cell;
    }

    // HAVING 比较符判断：compare_cell 返回 cmp，compare_having 根据 =/</> 等操作符判断真假。
    bool compare_having(int cmp, ast::SvCompOp op) const {
        switch (op) {
            case ast::SV_OP_EQ: return cmp == 0;
            case ast::SV_OP_NE: return cmp != 0;
            case ast::SV_OP_LT: return cmp < 0;
            case ast::SV_OP_GT: return cmp > 0;
            case ast::SV_OP_LE: return cmp <= 0;
            case ast::SV_OP_GE: return cmp >= 0;
        }
        return false;
    }

    // 判断一个分组是否通过 HAVING。
    // HAVING 是“聚合之后”的过滤，所以这里看的是 GroupState 中已经算好的聚合结果。
    bool pass_having(const GroupState &state) const {
        for (auto &cond : having_conds_) {
            auto lhs = state.aggs.at(agg_key(cond->lhs));
            if (cond->lhs->agg_type == ast::AGG_AVG && lhs.count > 0) {
                lhs.float_val /= static_cast<float>(lhs.count);
            }
            auto rhs = rhs_cell(cond->rhs);
            if (!compare_having(compare_cell(lhs, rhs), cond->op)) {
                return false;
            }
        }
        return true;
    }

    // 把一个 Cell 写入输出 RmRecord。
    // 聚合结果虽然不是表里的真实记录，但执行器之间仍然统一用 RmRecord 传递结果。
    void write_cell(RmRecord *rec, const ColMeta &col, const Cell &cell) const {
        if (col.type == TYPE_INT) {
            *reinterpret_cast<int *>(rec->data + col.offset) = cell.int_val;
        } else if (col.type == TYPE_BIGINT) {
            int64_t value = cell.type == TYPE_BIGINT ? cell.bigint_val : cell.int_val;
            *reinterpret_cast<int64_t *>(rec->data + col.offset) = value;
        } else if (col.type == TYPE_DATETIME) {
            int64_t value = cell.type == TYPE_DATETIME ? cell.datetime_val : cell.int_val;
            *reinterpret_cast<int64_t *>(rec->data + col.offset) = value;
        } else if (col.type == TYPE_FLOAT) {
            float value = cell.type == TYPE_FLOAT ? cell.float_val
                          : cell.type == TYPE_BIGINT ? static_cast<float>(cell.bigint_val)
                                                     : static_cast<float>(cell.int_val);
            *reinterpret_cast<float *>(rec->data + col.offset) = value;
        } else {
            memset(rec->data + col.offset, 0, col.len);
            memcpy(rec->data + col.offset, cell.str_val.c_str(), std::min<int>(col.len, cell.str_val.size()));
        }
    }

    // 更新某个聚合函数的中间状态。
    //
    // COUNT: 每来一条输入记录就 +1。
    // SUM:   按输入类型累加。
    // AVG:   保存累加和，并额外用 count 记录数量，最后输出时再除。
    // MAX/MIN: 第一次输入先初始化，之后不断比较并保留最大/最小值。
    void update_agg(Cell &agg, const Cell &input, ast::AggType type) {
        if (type == ast::AGG_COUNT) {
            agg.type = TYPE_INT;
            agg.int_val++;
            agg.initialized = true;
            return;
        }
        if (type == ast::AGG_SUM) {
            agg.type = input.type == TYPE_FLOAT ? TYPE_FLOAT : input.type == TYPE_BIGINT ? TYPE_BIGINT : TYPE_INT;
            if (input.type == TYPE_FLOAT) {
                agg.float_val += input.float_val;
            } else if (input.type == TYPE_BIGINT) {
                agg.bigint_val += input.bigint_val;
            } else {
                agg.int_val += input.int_val;
            }
            agg.initialized = true;
            return;
        }
        if (type == ast::AGG_AVG) {
            agg.type = TYPE_FLOAT;
            agg.float_val += input.type == TYPE_FLOAT ? input.float_val
                             : input.type == TYPE_BIGINT ? static_cast<float>(input.bigint_val)
                                                        : static_cast<float>(input.int_val);
            agg.count++;
            agg.initialized = true;
            return;
        }
        if (!agg.initialized || (type == ast::AGG_MAX && compare_cell(input, agg) > 0) ||
            (type == ast::AGG_MIN && compare_cell(input, agg) < 0)) {
            agg = input;
        }
    }

   public:
    AggregateExecutor(std::unique_ptr<AbstractExecutor> prev,
                      std::vector<std::shared_ptr<ast::SelectItem>> select_items,
                      std::vector<TabCol> group_cols,
                      std::vector<std::shared_ptr<ast::HavingExpr>> having_conds,
                      std::vector<TabCol> output_cols) {
        prev_ = std::move(prev);
        select_items_ = std::move(select_items);
        group_cols_ = std::move(group_cols);
        having_conds_ = std::move(having_conds);
        len_ = 0;
        for (size_t i = 0; i < select_items_.size(); ++i) {
            ColMeta col;
            col.tab_name = "";
            col.name = output_cols[i].col_name;
            col.offset = len_;
            auto &item = select_items_[i];
            if (!item->is_agg) {
                auto src = prev_->get_col_offset({item->col->tab_name, item->col->col_name});
                col.type = src.type;
                col.len = src.len;
            } else if (item->agg_type == ast::AGG_COUNT) {
                col.type = TYPE_INT;
                col.len = sizeof(int);
            } else if (item->agg_type == ast::AGG_AVG) {
                col.type = TYPE_FLOAT;
                col.len = sizeof(float);
            } else {
                auto src = prev_->get_col_offset({item->col->tab_name, item->col->col_name});
                col.type = src.type;
                col.len = src.len;
            }
            len_ += col.len;
            cols_.push_back(col);
        }
        cursor_ = 0;
    }

    void beginTuple() override {
        // 聚合执行器不是“一条输入立刻输出一条结果”。
        // 它需要先把子执行器 prev_ 的所有输入记录扫描完，完成分组和聚合计算，
        // 再把最终结果组装到 tuples_ 中，供 Next/nextTuple 逐条输出。
        tuples_.clear();
        std::map<std::string, GroupState> groups;
        std::vector<std::string> order;
        std::vector<std::shared_ptr<ast::SelectItem>> agg_items;
        std::set<std::string> agg_keys;

        // 收集 SELECT 列表里需要计算的聚合函数，去重后放入 agg_items。
        // 例如 select count(*), count(*) 只需要维护一份 COUNT(*) 状态。
        for (auto &item : select_items_) {
            if (item->is_agg && agg_keys.insert(agg_key(item)).second) {
                agg_items.push_back(item);
            }
        }

        // HAVING 里可能出现 SELECT 列表没有写出的聚合函数。
        // 例如 select id from t group by id having count(*) > 1;
        // 即使 count(*) 不输出，也必须计算它用于过滤分组。
        for (auto &cond : having_conds_) {
            if (agg_keys.insert(agg_key(cond->lhs)).second) {
                agg_items.push_back(cond->lhs);
            }
        }

        // 扫描子执行器的所有输入记录。
        // 对每条记录：
        //   1. 读取 group by 字段，确定它属于哪个分组；
        //   2. 读取聚合函数参数字段，更新该分组的聚合状态。
        for (prev_->beginTuple(); !prev_->is_end(); prev_->nextTuple()) {
            auto rec = prev_->Next();
            std::vector<Cell> group_cells;
            for (auto &group_col : group_cols_) {
                group_cells.push_back(read_cell(rec.get(), prev_->get_col_offset(group_col)));
            }
            std::string key = group_cols_.empty() ? "__all__" : group_key(group_cells);
            if (groups.find(key) == groups.end()) {
                groups[key].group_cells = group_cells;
                order.push_back(key);
            }
            auto &state = groups[key];
            for (auto &item : agg_items) {
                Cell input;
                if (!item->count_star) {
                    input = read_cell(rec.get(), prev_->get_col_offset({item->col->tab_name, item->col->col_name}));
                }
                update_agg(state.aggs[agg_key(item)], input, item->agg_type);
            }
        }

        // SQL 中 count(*) 在空输入上也应该返回 0。
        // 如果没有 group by 且没有任何输入记录，这里手动创建一个 "__all__" 分组，
        // 并把 COUNT 类聚合初始化为 0。
        if (groups.empty() && group_cols_.empty()) {
            groups["__all__"] = GroupState();
            order.push_back("__all__");
            for (auto &item : select_items_) {
                if (item->is_agg && item->agg_type == ast::AGG_COUNT) {
                    Cell zero;
                    zero.type = TYPE_INT;
                    zero.int_val = 0;
                    zero.initialized = true;
                    groups["__all__"].aggs[agg_key(item)] = zero;
                }
            }
            for (auto &cond : having_conds_) {
                if (cond->lhs->agg_type == ast::AGG_COUNT) {
                    Cell zero;
                    zero.type = TYPE_INT;
                    zero.int_val = 0;
                    zero.initialized = true;
                    groups["__all__"].aggs[agg_key(cond->lhs)] = zero;
                }
            }
        }

        // 将每个分组的聚合状态转换成最终输出记录。
        // HAVING 在这里生效：不过 HAVING 的分组不会写入 tuples_。
        for (auto &key : order) {
            auto &state = groups[key];
            if (!pass_having(state)) {
                continue;
            }
            auto out = std::make_unique<RmRecord>(len_);
            for (size_t i = 0; i < select_items_.size(); ++i) {
                auto &item = select_items_[i];
                Cell cell;
                if (item->is_agg) {
                    // 聚合列：从该分组的 aggs 中取出最终状态。
                    // AVG 的状态里保存的是累加和，这里输出前才除以 count。
                    cell = state.aggs.at(agg_key(item));
                    if (item->agg_type == ast::AGG_AVG && cell.count > 0) {
                        cell.float_val /= static_cast<float>(cell.count);
                    }
                } else {
                    // 普通列只允许是 group by 列。
                    // 输出时从 group_cells 中取对应的分组值。
                    for (size_t group_idx = 0; group_idx < group_cols_.size(); ++group_idx) {
                        if (group_cols_[group_idx].tab_name == item->col->tab_name &&
                            group_cols_[group_idx].col_name == item->col->col_name) {
                            cell = state.group_cells[group_idx];
                            break;
                        }
                    }
                }
                write_cell(out.get(), cols_[i], cell);
            }
            tuples_.push_back(std::move(out));
        }
        cursor_ = 0;
    }

    void nextTuple() override {
        if (cursor_ < tuples_.size()) {
            cursor_++;
        }
    }

    bool is_end() const override { return cursor_ >= tuples_.size(); }
    size_t tupleLen() const override { return len_; }
    const std::vector<ColMeta> &cols() const override { return cols_; }
    std::string getType() override { return "AggregateExecutor"; }
    ColMeta get_col_offset(const TabCol &target) override { return *get_col(cols_, target); }
    Rid &rid() override { return _abstract_rid; }
    std::unique_ptr<RmRecord> Next() override {
        auto rec = std::make_unique<RmRecord>(len_);
        memcpy(rec->data, tuples_[cursor_]->data, len_);
        return rec;
    }
};
