#include <homework/exp3/tree.h>
#include <iostream>
#include <stack>

void dlr(const BinaryTreeNode<char> *node) {
    if (!node || node->isNull()) {
        return;
    }

    std::cout << node->getData() << " ";
    dlr(node->getLeft());

    dlr(node->getRight());


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

/**
 * 不用标记位版本
 * 其左子树一路压栈，弹栈的时候取右子树，重复进行
 * 思路很简单，但是实际有一些细节需要考虑
 * - 怎么处理null节点
 * - R子树压栈的写法怎么避免一直重复某一节点
 * - R子树不压栈的写法怎么避免执行top的时候栈不为空
 * 下面这是多次优化后较为精简优雅的写法，不用各种“卫语句”，或者if
 * @param node
 */
void ldr2(const BinaryTreeNode<char> *node) {
    if (node == nullptr) {return;}

    std::stack<const BinaryTreeNode<char> *> stack;

    auto curr = node;

    //abc#d##e##f##

    while ((curr && !curr->isNull()) || !stack.empty()) {
        while (curr && !curr->isNull()) {
            stack.push(curr);
            curr = curr->getLeft();
        }

        curr = stack.top();

        std::cout << curr->getData() << " ";
        curr = curr->getRight();
        stack.pop();
    }

}


// 使用标记位 abc#d##e##f##
void lrd(const BinaryTreeNode<char> *node) {
    if (node == nullptr) {return;}

    std::stack<const BinaryTreeNode<char> *> stack;

    const BinaryTreeNode<char> *curr = node;

    while (curr || !stack.empty()) {
        while (curr && !curr->isNull() && !curr->isFlag()) {
            stack.push(curr);
            curr = curr->getLeft();
        }

        curr = stack.top();
        if (!curr->isFlag() && !curr->isNull()) {
            curr->setFlag(true);
            curr = curr->getRight();
        } else {
            std::cout << curr->getData() << " ";
            stack.pop();
            // 把手一挥不带走一片云彩~
            curr->setFlag(false);
            curr = nullptr;
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

void build_tree() {
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

void dlr_build() {
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
            if (curr->getData() == 'g') {
                int i = 1;
            }
            auto temp = setNode(incident, curr, "R:", false);

            curr->setRight(temp);
            stack.push(temp);
            incident++;
        } else {
            incident--;
            stack.pop();
        }


    }
    std::cout << "dlr: ";
    dlr(&root);
//    abc#d##e##f##

    std::cout << "\n";

    std::cout << "ldr: ";
    ldr(&root);
    std::cout << "\n";


    std::cout << "ldr: ";
    ldr2(&root);

    std::cout << "\n";


    std::cout << "lrd: ";
    lrd(&root);


}


int main() {

    dlr_build();
//    build_tree();


    /*
     *              a
     *            /   \
     *           b     f
     *          / \
     *         c   e
     *          \
     *           d
     */

    /*
    *              a
    *            /   \
    *           f     b
    *                / \
    *               c   e
    *                \
    *                 d
     *
    */


    /*
       *              a
       *            /   \
       *           f     b
       *          / \   / \
       *         c   h g   e
       *          \
       *           d
        *
       */
    // af##bc#d##e##
    // afc#d##h##bg##e##
    return 0;
}

