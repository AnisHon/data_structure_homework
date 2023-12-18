//
// Created by happy on 2023/12/13.
//
#include "util/binary_tree_util.hpp"

#ifndef CPPPROJECT01_BLACK_RED_TREE_HPP
#define CPPPROJECT01_BLACK_RED_TREE_HPP

namespace data_structure {

    template <class T>
    class BlackRedTree {
        const static bool BLACK = true;
        const static bool RED = false;

        struct Node {
            T element;
            Node *left;
            Node *right;
            bool color;

            explicit Node(T element) : element(element), left(nullptr), right(nullptr),
                                                                   color(RED) {}
        };

        Node *root_;

        Node *create_node(T element) {
            return new Node(element);
        }


        Node *add(Node *root, T element) {
            if (root == nullptr) {
                return create_node(element);
            }
            if (root->element < element) {
                root->right = add(root->right, element);
            } else if (root->element > element) {
                root->left = add(root->left, element);
            } else {
                return root;
            }
            return root;
        }

        void dlr(Node *root) {
            if (root == nullptr) return;
            std::cout << root->element << " ";
            dlr(root->right);
            dlr(root->left);
        }

    public:
        explicit BlackRedTree(T element): root_(create_node(element)) {}

        void insert(T element) {
            root_ = add(root_, element);
        }

        void print_dlr() {

            std::cout << "\n";
        }
    };
}



#endif //CPPPROJECT01_BLACK_RED_TREE_HPP
