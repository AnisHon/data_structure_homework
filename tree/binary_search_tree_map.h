//
// Created by Anis Han on 2024/1/26.
//

#ifndef CPPPROJECT01_BINARY_SEARCH_TREE_MAP_H
#define CPPPROJECT01_BINARY_SEARCH_TREE_MAP_H

#include <iostream>
#include "binary_tree_map.h"
template<typename K, typename V>
class BinarySearchTreeMap : public BinaryTreeMap<K, V> {
    struct Node {
        typename BinaryTreeMap<K, V>::Pair element;
        Node *left;
        Node *right;

        Node(): element{}, left{}, right{} {}
        explicit Node(K e, V v): element{e, v}, left{}, right{} {}
    };
private:
    Node *root_;

    auto put_(Node *root, K k, V v) -> void {
        Node *parent = nullptr;
        Node *current = root;
        while (current) {
            parent = current;
            if (current->element.key > k) {
                current = current->left;
            } else if (current->element.key < k) {
                current = current->right;
            } else {
                return;
            }
        }
        (parent->element.key > k ? parent->left : parent->right) = new Node(k, v);
    }


    auto maintain(Node *root) -> Node * {
        Node *temp;
        if (root == nullptr) return nullptr;
        if (root->left != nullptr && root->right != nullptr) {
            Node *max = find_max(root->left);
            root->element = max->element;
            erase_(root->right, max->element.key);
        } else if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else {
            temp = root->left == nullptr ? root->right : root->left;
            delete root;
            root = temp;
        }
        return root;
    }

    auto erase_(Node *root, K k) -> Node * {
        if (root == nullptr) return nullptr;
        if (root->element.key > k) {
            root->left = erase_(root->left, k);
        } else if (root->element.key < k) {
            root->right = erase_(root->right, k);
        } else {
            root = maintain(root);
        }
        return root;
    }

public:
    BinarySearchTreeMap(): root_{nullptr} {}


    auto put(K t, V v) -> void override {
        if (root_ == nullptr) {
            root_ = new Node(t, v);
        } else {
            put_(root_, t, v);
        }
    }

    auto get(K k) -> V * override {
        Node *current = root_;
        while (current) {
            if (current->element.key > k) {
                current = current->left;
            } else if (current->element.key < k) {
                current = current->right;
            } else {
                return &(current->element.value);
            }
        }
        return nullptr;
    }


    auto erase(K k) -> void override {
        root_ = erase_(root_, k);
    }

    auto size() -> int override {
        int size = 0;
        lrd(root_, [&] (Node *node) {++size;});
        return size;
    }

    auto print_dlr() -> void {
        dlr(root_, [] (Node *node) {std::cout << node->element << " ";});
    }

    ~BinarySearchTreeMap() {
        lrd(root_, [] (Node *node) {delete node;});
    }

    auto get_depth() -> int {
        return ::get_depth(root_);
    }

};
#endif //CPPPROJECT01_BINARY_SEARCH_TREE_MAP_H
