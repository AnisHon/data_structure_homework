#include <iostream>
#include "BinarySearchTree.h"
#include "avl_tree.h"
#include "binary_search_tree_map.h"

using namespace std;

int main() {

    BinarySearchTreeMap<int, char> b;

    int array[] = {3, 1, 7, 9, 5, 0, 6, 4, 2, 8};
    for (auto &i : array) {
        b.put(i, i + 'A');
    }

    b.print_dlr();

    return 0;
}
