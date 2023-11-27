#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <map>

using namespace std;

/* Naive solution */

int main() {
    int N, Q, start_i, end_i, q_j;
    cin >> N >> Q;

    map<int, int> vals;

    for (int i = 0; i < N; ++i) {
        cin >> start_i >> end_i;

        for (int j = start_i; j <= end_i; ++j) {
            if (vals.count(j) == 0) {
                vals[j] = 0;
            }

            vals[j] += 1;
        }
    }

    for (int i = 0; i < Q; ++i) {
        cin >> q_j;
        cout << vals[q_j] << " ";
    }

    return 0;
}
