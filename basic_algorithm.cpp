//
// Created by happy on 2023/12/4.
//

#include "basic_algorithm.h"


namespace basic_algorithm {
    long long qpow_recursive(int num, int index) {
        if (index == 0) {
            return 1;
        }

        if (index % 2 == 0) {
            const long long temp = qpow_recursive(num, index / 2);
            return temp * temp;
        } else {
            return num * qpow_recursive(num, index - 1);
        }
    }








    long long qpow(int num, int index) {
        long long result = 1;

        while (index) {
            if (index & 1) {
                result = result * num;
            }
            num *= num;
            index >>= 1;
        }

        return result;
    }

    string plus(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        auto size1 = num1.size();
        auto size2 = num2.size();
        std::vector<int> n(size1 + size2);
        string result;
        int num = 0;

        for (auto i = 0; i < size1; ++i) {
            for (auto j = 0; j < size2; ++j) {
                n[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = 0; i < size1 + size2; ++i) {
            num += n[i];
            n[i] = num % 10;
            num /= 10;
        }

        auto p = size1 + size2 - 1;
        while (p && n[p--] == 0) n.pop_back();
        std::reverse(n.begin(), n.end());
        for (const auto &item: n) result.push_back(item + '0');
        return result;
    }

}