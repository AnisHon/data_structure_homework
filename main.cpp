#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "avl_tree.hpp"
#include "basic_algorithm.h"
#include <string>
#include "black_red_tree.hpp"
#include <stack>
#include <list>
using std::cout, std::string;

int main() {
    data_structure::BlackRedTree<int> blackRedTree(0);
    bool c;
    for (int i = 0; i < 10; ++i) {
         blackRedTree.insert(i);
    }


    blackRedTree.print_dlr();
    return 0;
}