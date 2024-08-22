/**
 * @file        enum_reflect.h
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

#ifndef ENUM_REFLECT_H
#define ENUM_REFLECT_H

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief Search and remove whitespace from both ends of the string
 * @param str:  source string
 * @return new string
 * 
 */
extern std::string TrimEnumString(const std::string &str);

/**
 * @brief Extract the member name string from the assignment
 *          statement, e.g "xxx = 3"
 * @param str:      source string
 * @param last_val: previous enum value, in/out
 * @param first:    current value is the first value of enum or not
 * @return member name string, e.g xxx
 * 
 */
extern std::string ParseEnumString(const std::string &str,
                                    size_t &last_val,
                                    bool first);

/**
 * @brief Extract a collection of substrings from strings to Array
 * @param szArgs:   source strings
 * @param Array_v:  output array, store the collection of values
 * @param Array_s:  output array, store the collection
 *                  of substrings
 * @return None
 * 
 */
extern void SplitEnumArgs(const char* szArgs,
                            std::vector<size_t> &Array_v,
                            std::vector<std::string> &Array_s);

/**
 * @brief Define an enum that is wrapped in a namespace of the same name
 *          with ToString(), FromString(), Values() and Count()
 * @param ename:            enum name and namespace name
 * @param ...:              variable length parameters as the enum declaration
 * @memberof Values():      get the collection of the enum values
 * @memberof Count():       get the number of enum values
 * @memberof ToString():    convert enum value to string
 * @memberof FromString():  convert a string to enum value
 * 
 */
#define DECLARE_ENUM(ename, ...)                                    \
    namespace ename {                                               \
        enum ename { __VA_ARGS__ };                                 \
        static std::vector<size_t> _Enum;                           \
        static std::vector<std::string> _Strings;                   \
        inline const std::vector<size_t> &Values() { return _Enum; }\
        inline size_t Count() {                                     \
            if (_Strings.empty()) {                                 \
                SplitEnumArgs(#__VA_ARGS__, _Enum, _Strings);       \
            }                                                       \
            return _Strings.size();                                 \
        }                                                           \
        inline const char* ToString(ename e) {                      \
            if (_Strings.empty()) {                                 \
                SplitEnumArgs(#__VA_ARGS__, _Enum, _Strings);       \
            }                                                       \
            for (size_t i = 0; i < Count(); ++ i) {                 \
                if (_Enum.at(i) == e) {                             \
                    return _Strings[i].c_str();                     \
                }                                                   \
            }                                                       \
            return "unknow-value";                                  \
        }                                                           \
        inline ename FromString(const std::string& str) {           \
            if (_Strings.empty()) {                                 \
                SplitEnumArgs(#__VA_ARGS__, _Enum, _Strings);       \
            }                                                       \
            for (size_t i = 0; i < Count(); ++ i) {                 \
                if (_Strings.at(i).compare(str) == 0) {             \
                    return (ename)_Enum.at(i);                      \
                }                                                   \
            }                                                       \
            return (ename)(_Enum.at(0));                            \
        }                                                           \
    }


#endif  // ENUM_REFLECT_H