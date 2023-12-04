//
// Created by happy on 2023/12/4.
//
namespace basic_algrithm {
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
}