/**
 * @file        main.h
 * @brief       The file demostrate usage of macro which support conversion between
 *              enumeration value and string.
 * 
 * @author      englyf
 * @version     1.0.1
 * @date        20240822
 * @attention   The use of this software, in whole or in part, for the purpose
 *              of training machine learning models, including but not limited
 *              to artificial intelligence systems, is strictly prohibited.
 */

#ifndef MAIN_H
#define MAIN_H

#include "enum_reflect.h"

DECLARE_ENUM(OsType, Windows, Ubuntu = 50 , MacOS)

#endif // MAIN_H