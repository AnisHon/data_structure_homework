//
// Created by Anis Han on 2024/1/26.
//

#ifndef CPPPROJECT01_BINARY_TREE_MAP_H
#define CPPPROJECT01_BINARY_TREE_MAP_H

#include <ostream>

template <typename K, typename V>
class BinaryTreeMap {

public:
    struct Pair {
        K key;
        V value;

        Pair() {}

        Pair(K k, V v): key(k), value(v) {}

        friend std::ostream &operator<<(std::ostream &os, const Pair &pair) {
            os << "{" << pair.key << "," << pair.value << "}";
            return os;
        }

        bool operator<(const Pair &rhs) const {
            return key < rhs.key;
        }

        bool operator>(const Pair &rhs) const {
            return rhs < *this;
        }

        bool operator<=(const Pair &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const Pair &rhs) const {
            return !(*this < rhs);
        }

    };

private:
    struct Node {
        Pair element;
        Node *left;
        Node *right;
    };



public:
    virtual auto put(K t, V v) -> void = 0;

    virtual auto get(K k) -> V * = 0;

    virtual auto erase(K k) -> void = 0;

    virtual auto size() -> int = 0;

};

#endif //CPPPROJECT01_BINARY_TREE_MAP_H
