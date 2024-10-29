//
// Created by Anis Han on 2024/1/27.
//

#ifndef CPPPROJECT01_BR_TREE_H
#define CPPPROJECT01_BR_TREE_H

#include <iostream>

#include "BinaryTree.h"

template<typename T>
class BRTree: public BinaryTree<T> {

    enum Color {
        RED = 0, BLACK = 1
    };

    struct Node {
        T element;
        Node *parent;
        Node *left;
        Node *right;
        Color color;

        Node() = default;
        explicit Node(T t): element{t}, parent{nullptr}, left{nullptr}, right{nullptr}, color(RED) {}

    };

    Node *root_;

    auto get_color(Node *node) -> Color {
        return node == nullptr ? BLACK : node->color;
    }

    auto set_color(Node *node, Color color) -> void {
        if (node == nullptr) return;
        node->color = color;
    }

    /*
     *      x：node            y
     *        y             x     z
     *      a   z             a
     */
    auto left_rotation(Node *node) -> void {
        if (node == nullptr) return;
        auto parent = node->parent;
        auto right = node->right;

        if (right->left != nullptr) {
            right->left->parent = node;
        }

        right->parent = parent;
        node->parent = right;
        node->right = right->left;
        right->left = node;



        if (parent == nullptr) {
            root_ = right;
        } else {
            (parent->left == node ? parent->left : parent->right) = right;
        }

    }

    auto right_rotation(Node *node) {
        if (node == nullptr) return;
        auto parent = node->parent;
        auto left = node->left;

        if (left->right != nullptr) {
            left->right->parent = node;
        }

        left->parent = parent;
        node->parent = left;
        node->left = left->right;
        left->right = node;

        if (parent == nullptr) {
            root_ = left;
        } else {
            (parent->left == node ? parent->left : parent->right) = left;
        }
    }

    auto static left_node(Node *root) -> Node * {
        return root == nullptr ? nullptr : root->left;
    }

    auto  static  right_node(Node *root) -> Node * {
        return root == nullptr ? nullptr : root->right;
    }

    auto parent_node(Node *root) -> Node * {
        return root == nullptr ? nullptr : root->parent;
    }

    auto brother_node(Node *root, Node *parent) -> Node * {
        if (parent == nullptr) return nullptr;
        return parent->left == root ? parent->right : parent->left;
    }

    auto put_rotation(Node *root, Node *parent, Node *grandparent) {
        if (grandparent->left == parent) { //L
            if (parent->right == root) { //LR
                left_rotation(parent);
                root = parent;
            }
            root->parent->color = BLACK;       //LL
            set_color(root->parent->parent, RED);
            right_rotation(grandparent);

        } else { //R
            if (parent->left == root) { //RL
                right_rotation(parent);
                root = parent;
            }
            root->parent->color = BLACK;       //RR
            set_color(root->parent->parent, RED);
            left_rotation(grandparent);

        }
    }

    auto put_balance(Node *root) -> void {
        //if node is null or node is root or node's parent is black, stop.
        if (root == nullptr || get_color(root->parent) == BLACK || root->parent->parent == nullptr) return;

        auto parent = parent_node(root);
        auto grandparent = parent_node(parent);
        auto uncle = brother_node(parent, grandparent);

        if (get_color(uncle) == RED) {
            parent->color = BLACK;
            uncle->color = BLACK;
            grandparent->color = RED;
            put_balance(grandparent);
        } else {
            put_rotation(root, parent, grandparent);
        }


    }

    auto get_node(T t) -> Node *{
        Node *current = root_;
        while (current) {
            if (current->element > t) {
                current = current->left;
            } else if (current->element < t) {
                current = current->right;
            } else {
                break;
            }
        }
        return current;
    }

//    auto delete_balance_two_nephew(Node *del_node, Node *parent, Node *brother,
//                                   Node *left_nephew, Node *right_nephew) -> void {
//
//        if (parent->left == del_node) {
//            left_rotation(parent);
//            if (brother->color == RED) {
//                left_nephew->color = RED;
//            } else {
//                right_nephew->color = BLACK;
//            }
//
//        } else {
//            right_rotation(parent);
//            if (brother->color == RED) {
//                right_nephew->color = RED;
//            } else {
//                left_nephew->color = BLACK;
//            }
//        }
//        brother->color = parent->color;
//        brother->color = BLACK;
//
//
//    }
//
//    auto delete_balance_single_nephew(Node *del_node, Node *parent, Node *brother,
//                                     Node *left_nephew, Node *right_nephew) -> void {
//        if (parent->left == del_node) {
//            if (left_nephew == nullptr) {
//                left_nephew->color = parent->color;
//                right_rotation(brother);
//            } else {
//                right_nephew->color = BLACK;
//            }
//            left_rotation(parent);
//        } else {
//            if (left_nephew == nullptr) {
//                right_nephew->color = BLACK;
//            } else {
//                left_nephew->color = parent->color;
//                right_rotation(brother);
//            }
//            right_rotation(parent);
//        }
//        parent->color = BLACK;
//
//
//    }

    auto leaf_with_red_nephew(Node *del_node, Node *parent, Node *brother,
                              Node *left_nephew, Node *right_nephew) -> void {
        if (parent->left == del_node) { // L
            if (get_color(right_nephew) != RED) {
                right_rotation(brother);
                right_nephew = brother;
                brother = left_nephew;
            }
            right_nephew->color = BLACK;
            left_rotation(parent);

        } else { //R
            if (get_color(left_nephew) != RED) {
                left_rotation(brother);
                left_nephew = brother;
                brother = right_nephew;
            }
            left_nephew->color = BLACK;
            right_rotation(parent);
        }
        brother->color = parent->color;
        parent->color = BLACK;

    }

    auto leaf_without_red_nephew(Node *parent, Node *brother) -> void {
        parent->color = BLACK;
        brother->color = RED;
    }

    auto leaf_with_red_brother(Node *parent, Node *brother) -> void {
        parent->color = RED;
        brother->color = BLACK;
        //del_node is on the right
        if (parent->left == brother) {
            right_rotation(parent);
        } else {
            left_rotation(parent);
        }
    }


    auto delete_balance(Node *del_node) -> void {
        if (del_node == nullptr || del_node->color == RED) return;

        auto parent = del_node->parent;
        auto brother = brother_node(del_node, parent);
        auto right_nephew = brother->right;
        auto left_nephew = brother->left;

        if (brother->color == RED) {
            leaf_with_red_brother(parent, brother);
            brother = brother_node(del_node, parent);
            right_nephew = brother->right;
            left_nephew = brother->left;
        }

        if (get_color(right_nephew) == BLACK && get_color(left_nephew) == BLACK) {
            Color p_color = parent->color;
            leaf_without_red_nephew(parent, brother);
            if (p_color == BLACK) {
                delete_balance(parent);
            }

        } else {
            leaf_with_red_nephew(del_node, parent, brother, left_nephew, right_nephew);
        }


    }

    auto delete_node(Node *del_node) -> void {
        if (del_node == nullptr) return;
        //two children
        if (del_node->left != nullptr && del_node->right != nullptr) {
            auto max = find_max<Node>(del_node->left);
            del_node->element = max->element;
            del_node = max;
        }

        Node *replacement = del_node->left == nullptr ? del_node->right : del_node->left;

        // one child
        if (replacement != nullptr) {
            del_node->element = replacement->element;
            del_node = replacement;
        } else if (del_node->parent == nullptr) { //leaf and root
            delete del_node;
            root_ = nullptr;
            del_node = nullptr;
        } else {    //leaf
            auto parent = del_node->parent;
            delete_balance(del_node);
            (parent->left == del_node ? parent->left : parent->right) = nullptr;
            delete del_node;
            del_node = nullptr;
        }
        delete_node(del_node);
    }

public:
    BRTree(): root_{nullptr} {}

    explicit BRTree(T t): root_{new Node(t)} {}
    auto put(T t) -> void override {
        Node *current = root_;
        Node *parent = nullptr;

        if (current == nullptr) {
            root_ = new Node(t);
            root_->color = BLACK;
            return;
        }

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
        current = new Node(t);
        current->parent = parent;
        (parent->element > t ? parent->left : parent->right) = current;

        put_balance(current);
        root_->color = BLACK;
    }

    auto get(T t) -> T * override {
        auto temp = get_node(t);
        return temp == nullptr ? nullptr : &temp->element;
    }

    auto erase(T t) -> void override {
        if (root_ == nullptr) throw std::out_of_range("nothing here");
        auto node = get_node(t);
        delete_node(node);
        if (node == root_) {
            if (node->left == nullptr && node->right == nullptr) {
                root_ = nullptr;
            }
        }

    }

    auto size() -> int override {
        return 0;
    }

    auto lot_print() {
        lot(root_, [] (Node *root) {std::cout << root->element << (root->color == RED ? "R" : "B") << " ";});
    }

    ~BRTree() {
        lrd(root_, [] (Node *node) {delete node;});
    }
};

#endif //CPPPROJECT01_BR_TREE_H
