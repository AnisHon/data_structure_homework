//
// Created by Anis Han on 2024/1/26.
//

#ifndef CPPPROJECT01_BINARYTREE_H
#define CPPPROJECT01_BINARYTREE_H

#include <algorithm>
#include <queue>

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

template<typename Node>
auto get_depth(Node *root) -> int {
    if (root == nullptr) return 0;
    return std::max(get_depth(root->left), get_depth(root->right)) + 1;
}

template<typename Node, typename Action>
auto dlr(Node *root, Action action) -> void {
    if (root == nullptr) return;
    action(root);
    dlr(root->left, action);
    dlr(root->right, action);

}

template<typename Node, typename Consumer>
auto lot(Node *root, Consumer consumer) -> void {
    if (root == nullptr) return;
    std::queue<Node *> node_queue;
    node_queue.push(root);
    Node *front = nullptr;
    while (!node_queue.empty()) {
        front = node_queue.front();
        if (front->left) node_queue.push(front->left);
        if (front->right) node_queue.push(front->right);
        consumer(front);
        node_queue.pop();
    }
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
