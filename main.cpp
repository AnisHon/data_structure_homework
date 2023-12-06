#include <iostream>
#include <cstdlib>
#include <algorithm>
//#include "avl_tree.hpp"
//#include "basic_algorithm.h"

int mem[1010][1010] = {0};

auto main() -> int {
    using namespace std;

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int N, V; // num, volume
    cin >> N >> V;



    int v[1010] = {0};
    int w[1010] = {0};

    int m1[1010] = {0}; // n + 1
    int m2[1010] = {0}; // n

    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &v[i], &w[i]);
    }

    for (int i = 1; i <= N; i++) {
        cout << v[i] << " " << w[i] << endl;
    }

    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= V; ++j) {
            if (j < v[i]) {
                mem[i][j] = mem[i + 1][j];
                m1[j] = m1[j];
            } else {
                mem[i][j] = max(mem[i + 1][j], mem[i + 1][j - v[i]] + w[i]);
                m1[j] = max(m1[j], m1[j - v[i]] + w[i]);
            }
            memcpy(m1, m1,  sizeof m2);
        }
    }

    cout << mem[1][V] << " " << m1[V];


    return 0;
}
