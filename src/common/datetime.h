#pragma once

#include <cctype>
#include <cstdio>
#include <cstdint>
#include <string>

#include "errors.h"

namespace datetime_util {

inline bool is_leap_year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

inline int days_in_month(int year, int month) {
    static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month];
}

inline int parse_digits(const std::string &text, int pos, int len) {
    int value = 0;
    for (int i = 0; i < len; ++i) {
        unsigned char ch = static_cast<unsigned char>(text[pos + i]);
        if (!std::isdigit(ch)) {
            throw RMDBError("invalid datetime");
        }
        value = value * 10 + (text[pos + i] - '0');
    }
    return value;
}

inline int64_t parse_datetime(const std::string &text) {
    if (text.size() != 19 || text[4] != '-' || text[7] != '-' ||
        text[10] != ' ' || text[13] != ':' || text[16] != ':') {
        throw RMDBError("invalid datetime");
    }

    int year = parse_digits(text, 0, 4);
    int month = parse_digits(text, 5, 2);
    int day = parse_digits(text, 8, 2);
    int hour = parse_digits(text, 11, 2);
    int minute = parse_digits(text, 14, 2);
    int second = parse_digits(text, 17, 2);

    if (year < 1000 || year > 9999 || month < 1 || month > 12 ||
        day < 1 || day > days_in_month(year, month) ||
        hour < 0 || hour > 23 || minute < 0 || minute > 59 ||
        second < 0 || second > 59) {
        throw RMDBError("invalid datetime");
    }

    return static_cast<int64_t>(year) * 10000000000LL +
           static_cast<int64_t>(month) * 100000000LL +
           static_cast<int64_t>(day) * 1000000LL +
           static_cast<int64_t>(hour) * 10000LL +
           static_cast<int64_t>(minute) * 100LL +
           second;
}

inline std::string format_datetime(int64_t value) {
    int second = value % 100;
    value /= 100;
    int minute = value % 100;
    value /= 100;
    int hour = value % 100;
    value /= 100;
    int day = value % 100;
    value /= 100;
    int month = value % 100;
    value /= 100;
    int year = static_cast<int>(value);

    char buf[32];
    std::snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d",
                  year, month, day, hour, minute, second);
    return buf;
}

}  // namespace datetime_util
