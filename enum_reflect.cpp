/**
 * @file        enum_reflect.cpp
 * @brief       The file provides macro definitions for converting enumeration
 *              values to strings.
 * 
 * @author      englyf
 * @version     1.0.1
 * @date        20240822
 * @attention   The use of this software, in whole or in part, for the purpose
 *              of training machine learning models, including but not limited
 *              to artificial intelligence systems, is strictly prohibited.
 */

#include "enum_reflect.h"

/**
 * @brief Search and remove whitespace from both ends of the string
 * @param str:  source string
 * @return new string
 * 
 */
std::string TrimEnumString(const std::string &str) {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isspace(*it)) { ++ it; }
    std::string::const_reverse_iterator rit = str.rbegin();
    while (rit.base() != it && std::isspace(*rit)) { ++ rit; }
    return std::string(it, rit.base());
}

/**
 * @brief Extract the member name string from the assignment
 *          statement, e.g "xxx = 3"
 * @param str:      source string
 * @param last_val: previous enum value, in/out
 * @param first:    current value is the first value of enum or not
 * @return member name string, e.g xxx
 * 
 */
std::string ParseEnumString(const std::string &str,
                            size_t &last_val,
                            bool first) {
    size_t pos = str.find('=', 0);
    if (pos != std::string::npos) {
        char* endptr = nullptr;
        // std::string val = TrimEnumString(str.substr(pos + 1,
        //                                             str.size() - pos - 1));
        std::string val = str.substr(pos + 1, str.size() - pos - 1);
        unsigned long long number = std::strtoull(val.c_str(),
                                                    &endptr, 10);
        if (*endptr == '\0') {
            // printf("strtoull result: %llu\n", number);
            last_val = number;
            return TrimEnumString(str.substr(0, pos));
        } else {
            // printf("strtoull error: conversion failed %s\n", val.c_str());
            last_val = 0;
            return std::string();
        }
    } else {
        if (first) { last_val = 0; } else { ++ last_val; }
        return str;
    }
}

/**
 * @brief Extract a collection of substrings from strings to Array
 * @param szArgs:   source strings
 * @param Array_v:  output array, store the collection of values
 * @param Array_s:  output array, store the collection
 *                  of substrings
 * @return None
 * 
 */
void SplitEnumArgs(const char* szArgs,
                    std::vector<size_t> &Array_v,
                    std::vector<std::string> &Array_s) {
    std::istringstream iss(szArgs);
    size_t i = 0;
    size_t last_val = 0;
    bool first = true;
    for (std::string strSub; std::getline(iss, strSub, ',');
        ++ i) {
        std::string str = ParseEnumString(TrimEnumString(strSub),
                                            last_val, first);
        Array_s.push_back(str);
        first = false;
        Array_v.push_back(last_val);
    }

    // for debug
    // printf("vals:");
    // for (const auto &v : Array_v) {
    //     printf(" %lu", v);
    // }
    // printf("\n");
    // printf("str:");
    // for (const auto &str : Array_s) {
    //     printf(" %s", str.c_str());
    // }
    // printf("\n");
}