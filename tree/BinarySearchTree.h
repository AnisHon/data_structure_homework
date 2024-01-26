//
// Created by Anis Han on 2024/1/26.
//

#ifndef CPPPROJECT01_BINARYSEARCHTREE_H
#define CPPPROJECT01_BINARYSEARCHTREE_H
#include "BinaryTree.h"

template<typename T>
class BinarySearchTree : public BinaryTree<T> {
    struct Node {
        T element;
        Node *left;
        Node *right;

        Node(): element{}, left{}, right{} {}
        explicit Node(T e): element{e}, left{}, right{} {}
    };
private:
    Node *root_;

    auto put_(Node *root, T t) -> void {
        Node *parent = nullptr;
        Node *current = root;
        while (current) {
            parent = current;
            if (current->element > t) {
                current = current->left;
            } else if (current->element < t) {
                current = current->right;
            } else {
                return;
            }
        }
        (parent->element > t ? parent->left : parent->right) = new Node(t);
    }


    auto maintain(Node *root) -> Node * {
        Node *temp;
        if (root == nullptr) return nullptr;
        if (root->left != nullptr && root->right != nullptr) {
            Node *max = find_max(root->left);
            root->element = max->element;
            erase_(root->right, max->element);
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

    auto erase_(Node *root, T t) -> Node * {
        if (root == nullptr) return nullptr;
        if (root->element > t) {
            root->left = erase_(root->left, t);
        } else if (root->element < t) {
            root->right = erase_(root->right, t);
        } else {
            root = maintain(root);
        }
        return root;
    }

public:
    BinarySearchTree(): root_{nullptr} {}


    auto put(T t) -> void override {
        if (root_ == nullptr) {
            root_ = new Node(t);
        } else {
            put_(root_, t);
        }
    }

    auto get(T t) -> T * override {
        Node *current = root_;
        while (current) {
            if (current->element > t) {
                current = current->left;
            } else if (current->element < t) {
                current = current->right;
            } else {
                return &(current->element);
            }
        }
        return nullptr;
    }

    auto get_if(T t) -> T * {
        Node *current = root_;
        while (current) {
            if (current->element > t) {
                current = current->left;
            } else if (current->element < t) {
                current = current->right;
            } else {
                return &(current->element);
            }
        }
        return nullptr;
    }

    auto erase(T t) -> void override {
        root_ = erase_(root_, t);
    }

    auto size() -> int override {
        int size = 0;
        lrd(root_, [&] (Node *node) {++size;});
        return size;
    }

    auto print_dlr() -> void {
        dlr(root_, [] (Node *node) {std::cout << node->element << " ";});
    }

    ~BinarySearchTree() {
        lrd(root_, [] (Node *node) {delete node;});
    }

};


#endif //CPPPROJECT01_BINARYSEARCHTREE_H
