#include <iostream>
#include "avl_tree.hpp"



int main() {

    AvlTree<char> tree('A');
    for (char c = 'B'; c <= 'Z'; c++) {
        tree.insert(c);
    }
    tree.dlr_print();


    return 0;
}
