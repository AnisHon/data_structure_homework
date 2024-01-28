#include <iostream>
#include "sort_algorithm.h"
#include <random>
#include <algorithm>
#include "max_priority_queue.h"
#include "br_tree.h"
#include <queue>
using namespace std;




int main() {

    int array[] = {21, 8, 15, 3, 17, 10, 4, 12, 7, 19, 1, 13, 6, 18, 2, 14, 5, 11, 9};


    //sort::heap_sort(array, sizeof array / sizeof(int));

    MaxPriorityQueue<int> p;


    BRTree<int> b;

    for (const auto &item: array) {
        //cout << item << " ";
        b.put(item);
    }
//    while (!p.empty()) {
//        cout << p.pop() << " ";
//    }

    b.lot_print();
    cout << endl;
    b.erase(1);
    b.lot_print();
    cout << endl;
    b.erase(2);
    b.lot_print();
    cout << endl;
    b.erase(8);
    b.erase(9);
    b.lot_print();
    cout << endl;
    b.erase(7);
    b.lot_print();
    cout << endl;

    b.erase(6);
    b.lot_print();
    cout << endl;
    b.erase(21);
    b.lot_print();
    cout << endl;
    b.erase(19);
    b.lot_print();
    cout << endl;

    return 0;
}
