//
// Created by Anis Han on 2023/11/30.
//

#include <cmath>
#include <iostream>
#include <algorithm>

/**
 * AvlTree maintained some basic function of balanced binary tree.
 * @tparam T the value you want to store.
 */
template <typename T>
class AvlTree {
private:

    struct TreeNode {
        T element;
        TreeNode *left;
        TreeNode *right;
        int height;
        explicit TreeNode(T element) {
            this->element = element;
            left = right = nullptr;
            height = 1;
        }
    };

    TreeNode *root_;

    /**
     * create a node, but it's seemed unuseful.
     * @param element[in] element of new node
     * @return new node
     */
    static auto create_treeNode(T element) -> TreeNode * {
        return new TreeNode(element);
    }

    /**
     * get the height of a tree. null pointer safety
     * @param treeNode[in] a node
     * @return height
     */
    static auto get_height(TreeNode *treeNode) -> int {
        return treeNode == nullptr ? 0 : treeNode->height;
    }

    static auto max_height(TreeNode *node1, TreeNode *node2) -> int {
        return std::max(get_height(node1), get_height(node2));
    }

    /**
     * get the height difference between two tree
     * @param node1[in] the first tree
     * @param node2[in] the second tree
     * @return the difference
     */
    static auto height_difference(TreeNode *node1, TreeNode *node2) -> int {
        return get_height(node1) - get_height(node2);
    }

    /**
     * get the max subtree. null pointer safety.
     * @param treeNode[in] treeNode.
     * @return max subtree node;
     */
    static auto max_node(TreeNode *treeNode) -> TreeNode * {
        if (treeNode == nullptr) { return
            nullptr;
}
        TreeNode *temp = treeNode;
        while (temp->right) {
            temp = temp->right;
        }
        return temp;
    }

    /**
     * rotate tree left.
     * @param treeNode[in] the min imbalanced subtree.
     * @return new root node.
     */
    static auto left_rotation(TreeNode *treeNode) -> TreeNode * {
        TreeNode *right_node = treeNode->right;
        treeNode->right = right_node->left;
        right_node->left = treeNode;

        treeNode->height = max_height(treeNode->left, treeNode->right);
        right_node->height = max_height(right_node->left, right_node->right);
        return right_node;
    }

    /**
     * rotate tree right.
     * @param treeNode[in] the min imbalanced subtree.
     * @return new root node
     */
    static auto right_rotation(TreeNode *treeNode) -> TreeNode * {
        TreeNode *left_node = treeNode->right;
        treeNode->left = left_node->right;
        left_node->right = treeNode;

        treeNode->height = max_height(treeNode->left, treeNode->right);
        left_node->height = max_height(left_node->left, left_node->right);
        return left_node;
    }

    /**
     * handle LR issue
     * @param treeNode[in] the min imbalanced subtree
     * @return new root node
     */
    static auto left_right_rotation(TreeNode *treeNode) -> TreeNode * {
        treeNode->left = left_rotation(treeNode->left);
        return right_rotation(treeNode);
    }

    /**
     * handle RL issue
     * @param treeNode[in] the min imbalanced subtree
     * @return new root node
     */
    static auto right_left_rotation(TreeNode *treeNode) -> TreeNode * {
        treeNode->right = right_rotation(treeNode->right);
        return left_rotation(treeNode);
    }

    /**
     * balance a tree if needed
     * @param treeNode[in] check and balance the tree
     * @return new or origin root
     */
    static auto balance(TreeNode *treeNode) -> TreeNode * {
        auto difference = height_difference(treeNode->left, treeNode->right);
        if (treeNode == nullptr || ::abs(difference) <= 1) {
            return treeNode;
}

        int left_height = 0;
        int right_height = 0;
        if (difference > 0) {   //L
            left_height = treeNode->left != nullptr ? get_height(treeNode->left->left) : 0;
            right_height = treeNode->left != nullptr ? get_height(treeNode->left->right) : 0;

            if (left_height >= right_height) {   //LL
                treeNode = right_rotation(treeNode);
            } else {    //LR
                treeNode = left_right_rotation(treeNode);
            }

        } else {    //R
            left_height = treeNode->right != nullptr ? get_height(treeNode->right->left) : 0;
            right_height = treeNode->right != nullptr ? get_height(treeNode->right->right) : 0;

            if (right_height >= left_height) {   //RR
                treeNode = left_rotation(treeNode);
            } else {    //RL
                treeNode = right_left_rotation(treeNode);
            }
        }


        return treeNode;
    }

    /**
     * recursive function to add_node and balance the tree
     * @param treeNode subtree node
     * @param element element to be added
     * @return original or new root
     */
    static auto add_node(TreeNode *treeNode, T element) -> TreeNode * {
        if (treeNode == nullptr) {
            return create_treeNode(element);
        }
        if (element < treeNode->element) {
            treeNode->left = add_node(treeNode->left, element);
        } else if (element > treeNode->element) {
            treeNode->right = add_node(treeNode->right, element);
        }

        treeNode->height = max_height(treeNode->left, treeNode->right) + 1;
        return balance(treeNode);
    }



    


    static void dlr_print_impl(TreeNode *treeNode) {
        if (treeNode == nullptr) {
            return;
        }
        std::cout << treeNode->element << " ";
        dlr_print_impl(treeNode->left);
        dlr_print_impl(treeNode->right);
    }

public:
    explicit AvlTree(T element) : root_(create_treeNode(element)) {

    }

    void dlr_print() const {
        dlr_print_impl(root_);
        std::cout << "\n";
    }

    auto find(T element) -> TreeNode * {
        TreeNode *temp = root_;
        while (temp) {
            if (element < temp->element) {
                temp = temp->left;
            } else if (element > temp->element) {
                temp = temp->right;
            } else {
                break;
            }
        }
        return temp;
    }

    void insert(T element) {
        root_ = add_node(root_, element);
    }

};

