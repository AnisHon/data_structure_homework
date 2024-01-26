//
// Created by Anis Han on 2024/1/26.
//

#ifndef CPPPROJECT01_AVL_TREE_H
#define CPPPROJECT01_AVL_TREE_H

#include "BinaryTree.h"

template<typename T>
class AvlTree : public BinaryTree<T> {

    struct Node {
        T element;
        Node *left;
        Node *right;
        Node *parent;
        int height;

    };

public:
    auto put(T t) -> void override {

    }

    auto get(T t) -> T * override {
        return nullptr;
    }

    auto erase(T t) -> void override {

    }

    auto size() -> int override {
        return 0;
    }

};


#endif //CPPPROJECT01_AVL_TREE_H
