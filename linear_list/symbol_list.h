//
// Created by Anis Han on 2024/1/25.
//

#ifndef CPPPROJECT01_SYMBOL_LIST_H
#define CPPPROJECT01_SYMBOL_LIST_H

#include <list>
#include <iostream>
#include <stdexcept>
template <typename K, typename V>
class SymbolList {
    struct Node {
        K key;
        V value;
        Node(K k, V v) : key(k), value(v) {}

//        friend auto operator<<(std::ostream &os, Element &node) -> std::ostream &{
//            os << '[' << node.key << ',' << node.value << ']';
//            return os;
//        }

        friend std::ostream &operator<<(std::ostream &os, const Node &node) {
            os << "[" << node.key << "," << node.value << "]";
            return os;
        }
    };

    std::list<Node> list;

public:
    SymbolList(): list{} {}

    auto get(K k) -> V {
        auto temp = std::find_if(list.begin(), list.end(), [=] (auto &item) {return item.key == k;});
        if (temp == list.end()) throw std::out_of_range("not found");
        return temp->value;
    }

    auto put(K k, V v) -> void {
        auto temp = std::find_if(list.begin(), list.end(), [=] (auto &item) {return item.key == k;});
        if (temp == list.end()) {
            list.emplace_back(k, v);
        } else {
            temp->value = v;
        }

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

#endif //CPPPROJECT01_SYMBOL_LIST_H
