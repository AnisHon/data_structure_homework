//
// Created by happy on 2023/12/4.
//

#ifndef CPPPROJECT01_BASIC_ALGORITHM_H
#define CPPPROJECT01_BASIC_ALGORITHM_H
#include <string>
#include <algorithm>
#include <vector>

namespace basic_algorithm {
    using std::string;
    long long qpow_recursive(int num, int index);
    long long qpow(int num, int index);
    string plus(const string num1, const string num2);

}

#endif //CPPPROJECT01_BASIC_ALGORITHM_H
