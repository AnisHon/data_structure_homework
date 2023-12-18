//
// Created by happy on 2023/12/13.
//

#ifndef CPPPROJECT01_BINARY_TREE_UTIL_HPP
#define CPPPROJECT01_BINARY_TREE_UTIL_HPP

namespace util {
    template <typename T>
    T *left_rotation(T *root) {
        auto *right_node = root->right;
        root->right = right_node->left;
        right_node->left = root;
        return right_node;
    }

    template <typename T>
    T *right_rotation(T *root) {
        auto *left_node = root->left;
        root->left = left_node->right;
        left_node->right = root;
        return left_node;
    }

    template <typename T>
    T *left_right_rotation(T *root) {
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }

    template <typename T>
    T *right_left_rotation(T *root) {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }

    template <typename T>
    void dlr(T *root) {
        if (root == nullptr) return;
        std::cout << root->element << " ";
        dlr(root->right);
        dlr(root->left);
    }

}

#endif //CPPPROJECT01_BINARY_TREE_UTIL_HPP
