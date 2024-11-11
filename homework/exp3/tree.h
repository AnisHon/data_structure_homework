//
// Created by Anis Han on 24-11-11.
//

#ifndef CPPPROJECT01_TREE_H
#define CPPPROJECT01_TREE_H

#include <iostream>

template <class T>
class BinaryTreeNode {
    T data_;
    BinaryTreeNode *left_;
    BinaryTreeNode *right_;
    mutable bool flag_;
    bool null_;
public:

    explicit BinaryTreeNode(): data_{}, left_(nullptr), right_(nullptr), flag_(false), null_(false) {}
    explicit BinaryTreeNode(T data): data_(data), left_(nullptr), right_(nullptr), flag_(false), null_(false) {}

    T getData() const {
        return data_;
    }

    BinaryTreeNode &setData(T data) {
        data_ = data;
        return *this;
    }

    BinaryTreeNode *getLeft() const {
        return left_;
    }

    BinaryTreeNode & setLeft(BinaryTreeNode *left) {
        left_ = left;
        return *this;
    }

    BinaryTreeNode *getRight() const {
        return right_;
    }

    BinaryTreeNode & setRight(BinaryTreeNode *right) {
        right_ = right;
        return *this;
    }

    bool isFlag() const {
        return flag_;
    }

    const BinaryTreeNode & setFlag(bool flag) const {
        flag_ = flag;
        return *this;
    }

    bool isNull() const {
        return null_;
    }

    BinaryTreeNode & setNull(bool null) {
        null_ = null;
        return *this;
    }


};

template <class T>
class TreeNodeTemplate {
    T data_;
    bool isLeft_;
    bool isNull;

public:
    TreeNodeTemplate(): data_{}, isLeft_(false), isNull(false) {}

    friend std::istream & operator>>(std::istream &istream, TreeNodeTemplate &treeNodeTemplate) {
        char p;

        treeNodeTemplate.isLeft_ = p == 'L';
        treeNodeTemplate.isNull = p == 'NULL';
        if (!treeNodeTemplate.isNull) {
            istream >> p >> treeNodeTemplate.data_;
        }

        return istream;
    }

public:
    T getData() const {
        return data_;
    }

    bool isLeft() const {
        return isLeft_;
    }

};


#endif //CPPPROJECT01_TREE_H
