#include <homework/exp3/tree.h>
#include <iostream>
#include <stack>
#include <vector>

void dlr(const BinaryTreeNode<char> *node) {
    if (!node || node->isNull()) {
        return;
    }

    std::cout << node->getData() << " ";
    dlr(node->getLeft());

    dlr(node->getRight());


}

void lrd(BinaryTreeNode<char> *node) {
    std::stack<const BinaryTreeNode<char> *> stack;
    stack.push(node);



}

void ldr(BinaryTreeNode<char> *node) {

    std::stack<const BinaryTreeNode<char> *> stack;
    stack.push(node);

    while (!stack.empty()) {
        auto &curr = stack.top();

        // null leaf
        if (curr->isNull()) {
            stack.pop();
            continue;
        }

        // L子树访问完毕
        if (curr->isFlag()) {
            stack.pop();
            curr->setFlag(false);
            std::cout << curr->getData() << " ";
            stack.push(curr->getRight());
        } else {
            stack.push(curr->getLeft());
            curr->setFlag(true);
        }


    }





}

BinaryTreeNode<char> *setNode(int incident, BinaryTreeNode<char> *node, const std::string &info, bool is_print = true) {

    char  c;
    if (is_print) {
        for (int i = 0; i < incident; ++i) {
            std::cout << "--";
        }
        std::cout << node->getData() << "->" << info;
    }

    std::cin >> c;
    if (c == '#') {
        return &(new BinaryTreeNode<char>())->setNull(true);
    }
    return &(new BinaryTreeNode<char>())->setData(c).setNull(false);
}

int build_tree() {
    std::stack<BinaryTreeNode<char> *> stack;

    char c;
    std::cin >> c;

    BinaryTreeNode<char> root;
    root.setData(c);

    stack.push(&root);


    int incident = 0;
    while (!stack.empty()) {
        auto curr = stack.top();
        if (curr->isNull()) {
            incident--;
            stack.pop();
            continue;
        }



        if (!curr->getLeft()) {
            auto temp = setNode(incident, curr,  "L:");

            curr->setLeft(temp);
            stack.push(temp);
            incident++;

        } else if (!curr->getRight()) {
            auto temp = setNode(incident, curr, "R:");
            curr->setRight(temp);
            stack.push(temp);
            incident++;
        } else {
            incident--;
            stack.pop();
        }


    }

    dlr(&root);


}

int dlr_build() {
    std::stack<BinaryTreeNode<char> *> stack;

    char c;
    std::cin >> c;

    BinaryTreeNode<char> root;
    root.setData(c);

    stack.push(&root);


    int incident = 0;
    while (!stack.empty()) {
        auto curr = stack.top();
        if (curr->isNull()) {
            incident--;
            stack.pop();
            continue;
        }



        if (!curr->getLeft()) {
            auto temp = setNode(incident, curr,  "L:", false);

            curr->setLeft(temp);
            stack.push(temp);
            incident++;

        } else if (!curr->getRight()) {
            auto temp = setNode(incident, curr, "R:", false);
            curr->setRight(temp);
            stack.push(temp);
            incident++;
        } else {
            incident--;
            stack.pop();
        }


    }
    dlr(&root);
//    abc#d##e##f##

    std::cout << "\n";

    ldr(&root);





}


int main() {

    dlr_build();
//    build_tree();


    return 0;
}

