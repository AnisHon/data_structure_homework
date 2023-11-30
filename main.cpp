#include <iostream>
#include "avl_tree.hpp"



auto main() -> int {

    AvlTree<char> tree('A');
    for (char c = 'B'; c <= 'Z'; c++) {
        tree.insert(c);
    }
    tree.dlr_print();


    return 0;
}
