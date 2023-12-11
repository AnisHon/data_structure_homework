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
    avlTree.dlr_print();

    return 0;
}
