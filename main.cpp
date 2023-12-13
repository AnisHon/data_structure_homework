#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "avl_tree.hpp"



int main() {

    AvlTree<int> avlTree(0);
    for (int i = 1; i < 10; ++i) {
        //avlTree.dlr_print();
        avlTree.insert(i);
    }

    avlTree.erase(1);
    avlTree.insert(1);
    avlTree.erase(7);
    avlTree.erase(6);
    avlTree.erase(5);

    avlTree.insert({7, 6, 5});
    avlTree.erase(3);
    avlTree.erase(2);
    avlTree.dlr_print();

    return 0;
}
