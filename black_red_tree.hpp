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
        const static bool R = false;
        const static bool L = true;

        struct Node {
            T element;
            Node *left;
            Node *right;
            Node *parent;
            bool color;

            explicit Node(T element) : element(element), left(nullptr), parent(nullptr),
                                                                    right(nullptr), color(RED) {}
        };

        Node *root_;

        Node *create_node(T element) {
            return new Node(element);
        }

        void dlr(Node *root) {
            if (root == nullptr) return;
            std::cout << root->element << (root->color ? "B" : "R") << " ";
            dlr(root->right);
            dlr(root->left);
        }

        bool get_color(Node *root) {
            return root == nullptr ? BLACK : root->color;
        }

        void reconnect_parent(Node *old_root, Node *new_root, Node *parent) {
            if (old_root == nullptr || new_root == nullptr || parent == nullptr) return;
            if (parent->left == old_root) {
                parent->left = new_root;
            } else {
                parent->right = new_root;
            }
        }

        void right_rotation(Node *root) {
            if (root == nullptr) return;

            auto left = root->left;
            root->left = left->right;
            left->right = root;

            left->parent = root->parent;
            root->parent = left;
            if (root->left != nullptr) root->left->parent = root;

            reconnect_parent(root, left, left->parent);

        }

        //rotation without change root_;
        void left_rotation(Node *root) {
            if (root == nullptr) {

            }

            auto right = root->right;
            root->right = right->left;
            right->left = root;

            right->parent = root->parent;
            root->parent = right;
            if (root->right != nullptr) root->right->parent = root;

            reconnect_parent(root, right, right->parent);
        }

        bool get_pos(Node *root, Node *parent) {
            return parent->left == root;
        }
        Node *select_child(Node *parent, bool pos) {
            return pos == L ? parent->left : parent->right;
        }

        void left_right_rotation(Node *root) {
            //todo
        }

        void right_left_rotation(Node *root) {
            //todo
        }

        void rotation_maintain(Node *grandparent, Node *parent, Node *root, bool root_pos, bool parent_pos) {
            if (parent_pos == L) {
                if (root_pos == L) { // LL
                    parent->color = BLACK;
                    grandparent->color = RED;
                    right_rotation(grandparent);
                } else {
                    //todo
                }
            } else {
                if (root_pos == R) { //RR
                    parent->color = BLACK;
                    grandparent->color = RED;
                    left_rotation(grandparent);
                } else {
                    //todo
                }
            }
        }

        void maintain(Node *root) {
            // root is null
            if (root == nullptr) return;
            if (root->parent == nullptr) {
                root_ = root;
                root->color = BLACK;
                return;
            }
            if (root->parent->color == BLACK) return;
            auto parent = root->parent;
            auto grandparent = parent->parent;

            //now parent is red and grandparent must exist
            auto parent_pos = get_pos(parent, grandparent);
            auto root_pos = get_pos(root, parent);
            Node *uncle = select_child(grandparent, !parent_pos);
            //red uncle and parent
            if (get_color(uncle) == RED) {
                parent->color = BLACK;
                grandparent->color = RED;
                uncle->color = BLACK;
                maintain(grandparent);
            } else {    //black or not exists;
                rotation_maintain(grandparent, parent, root, root_pos, parent_pos);
            }
        }

    public:
        explicit BlackRedTree(T element) {
            root_ = create_node(element);
            root_->color = BLACK;
        }


        bool insert(T element) {
            auto parent = root_->parent;
            auto current = root_;
            // find position. if exists, return false;
            while (current != nullptr) {
                parent = current;
                if (current->element > element) {
                    current = current->left;
                } else if (current->element < element) {
                    current = current->right;
                } else {
                    return false;
                }
            }

            //put it in proper branch;
            current = create_node(element);
//            (parent->element > element ? parent->left : parent->right) = current;
            if (current == nullptr) return false;

            if (parent->element > element) {
                parent->left = current;
            } else {
                parent->right = current;
            }
            current->parent = parent;
            //maintain the balance
            maintain(current);
            return true;

        }

        void print_dlr() {

            dlr(root_);
            std::cout << "\n";
        }
    };
}



#endif //CPPPROJECT01_BLACK_RED_TREE_HPP
