/**
 * @file        main.cpp
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

#include "main.h"

int main() {
    printf("%d members:", (int)OsType::Count());
    for (const auto &val : OsType::Values()) {
        printf(" %s", OsType::ToString((OsType::OsType)val));
    }
    printf("\n");

    OsType::OsType type = OsType::MacOS;
    printf("The value of %s is: %d\n",
            OsType::ToString(type),
            OsType::FromString("MacOS"));
    return 0;
}
