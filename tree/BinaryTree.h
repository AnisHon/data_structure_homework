//
// Created by Anis Han on 2024/1/26.
//

#ifndef CPPPROJECT01_BINARYTREE_H
#define CPPPROJECT01_BINARYTREE_H

template<typename Node>
auto find_max(Node *root) -> Node * {
    if (root == nullptr) return nullptr;
    while (root->right) {
        root = root->right;
    }
    return root;
}

template<typename Node, typename Action>
auto lrd(Node *root, Action action) -> void {
    if (root == nullptr) return;
    lrd(root->left, action);
    lrd(root->right, action);
    action(root);
}

template<typename Node, typename Action>
auto dlr(Node *root, Action action) -> void {
    if (root == nullptr) return;
    action(root);
    dlr(root->left, action);
    dlr(root->right, action);

}



template <typename T>
class BinaryTree {

    struct Node {
        T element;
        Node *left;
        Node *right;
    };



public:
    virtual auto put(T t) -> void = 0;

    virtual auto get(T t) -> T * = 0;

    virtual auto erase(T t) -> void = 0;

    virtual auto size() -> int = 0;

};


#endif //CPPPROJECT01_BINARYTREE_H
