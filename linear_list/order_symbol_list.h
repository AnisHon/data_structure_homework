//
// Created by Anis Han on 2024/1/25.
//

#ifndef CPPPROJECT01_ORDER_SYMBOL_LIST_H
#define CPPPROJECT01_ORDER_SYMBOL_LIST_H

#include <list>
#include <iostream>
#include <stdexcept>
#include <ostream>
template <typename K, typename V>
class OrderSymbolList {
    struct Node {
        K key;
        V value;
        Node(K k, V v) : key(k), value(v) {}

        friend auto operator<<(std::ostream &os, const Node &node) -> std::ostream &{
            os << '[' << node.key << ',' << node.value << ']';
            return os;
        }
    };

    std::list<Node> list;

public:
    OrderSymbolList(): list{} {}

    auto get(K k) -> V {
        auto temp = std::find_if(list.begin(), list.end(), [=] (auto &item) {return item.key == k;});
        if (temp == list.end()) throw std::out_of_range("not found");
        return temp->value;
    }

    auto put(K k, V v) -> void {
        for (auto i = list.begin(); i != list.end(); ++i) {
            if (i->key == k) {
                i->value = v;
                return;
            } else if (i->key > k) {
                list.emplace(i, k, v);
                return;
            }
        }
        list.emplace_back(k, v);
    }

    auto erase(K k) -> void {
        list.remove_if([=] (auto &item) -> bool {return item.key == k;});
    }

    auto size() -> int {
        return list.size();
    }

    auto print() -> void {
        for (const auto &item: list) {
            std::cout << item << " ";
        }
    }


};

#endif //CPPPROJECT01_ORDER_SYMBOL_LIST_H
