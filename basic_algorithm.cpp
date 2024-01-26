//
// Created by happy on 2023/12/4.
//

#include "basic_algorithm.h"
#include <stack>
#include <sstream>

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


//    class Symbol {
//        enum Priority{
//            LOW = 1, MEDIUM = 2, HIGH = 3
//        };
//        char symbol_;
//        Priority priority_;
//
//    public:
//        explicit Symbol(char symbol) {
//            switch (symbol) {
//                case '+':
//                case '-':
//                    priority_ = LOW;
//                    break;
//                case '*':
//                case '/':
//                    priority_ = MEDIUM;
//                    break;
//                case '(':
//                    priority_ = HIGH;
//            }
//            symbol_ = symbol;
//        }
//
//        bool operator<=(Symbol &other) const {
//            return this->priority_ <= other.priority_;
//        }
//
//        char get_symbol() const {
//           return this->symbol_;
//        }
//
//    };
    
//    int calculate(string &expression) {
//        string suffix_expression;
//        suffix_expression.reserve(expression.size());
//        std::stack<int> result;
//        std::stack<Symbol> symbol;
//        for (const auto &item: expression) {
//            if ('0' <= item && item <= '9') {
//                suffix_expression.push_back(item);
//            } else {
//                Symbol temp(item);
//                if (item == ' ') { continue; }
//                if (item == ')') {
//                    while (symbol.top().get_symbol() != '(') {
//                        suffix_expression.push_back(' ');
//                        suffix_expression.push_back(symbol.top().get_symbol());
//                        symbol.pop();
//                    }
//                    symbol.pop();
//                    continue;
//                }
//                if (!symbol.empty() || symbol.top() <= temp) {
//                    symbol.push(temp);
//                } else {
//
//                    while (!symbol.empty() && !(symbol.top() <= temp)) {
//                        suffix_expression.push_back(symbol.top().get_symbol());
//                        symbol.pop();
//                    }
//                    symbol.push(temp);
//                }
//            }
//        }
//        while (!symbol.empty()) {
//            suffix_expression.push_back(symbol.top().get_symbol());
//            symbol.pop();
//        }
//        std::istringstream istr(suffix_expression);
//        string temp;
//        while (istr >> temp) {
//            if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
//        }
//
//
//    }




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

    string multiply(string num1, string num2) {
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