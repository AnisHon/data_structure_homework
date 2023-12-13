//
// Created by happy on 2023/12/13.
//
#include "util/tree_util.hpp"

#ifndef CPPPROJECT01_BLACK_RED_TREE_HPP
#define CPPPROJECT01_BLACK_RED_TREE_HPP

namespace data_structure {

    using namespace util;
    template <class T>
    class black_red_tree {
        const bool BLACK = true;
        const bool RED = false;

        struct BrtNode {
            T element;
            BrtNode *left;
            BrtNode *right;
            bool color;
        };

        BrtNode *root_;

        BrtNode *add(BrtNode *root, T element) {
            auto a = left_right_rotation(root);
        }



    };
}



#endif //CPPPROJECT01_BLACK_RED_TREE_HPP
