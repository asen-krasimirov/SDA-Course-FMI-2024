#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T, X, Y, ctr, x_i, x_j;
vector<int> parents, depth;

int Find(int v) {
    if (v == parents[v]) {
        return v;
    }

    return parents[v] = Find(parents[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) {
        return;
    }

    ctr--;

    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    parents[b] = a;

    if (depth[a] == depth[b]) {
        depth[a]++;
    }
}

int main() {
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> X >> Y;

        parents = vector<int>(X);

        for (int j = 0; j < X; ++j) {
            parents[j] = j;
        }

        depth = vector<int>(X, 1);
        ctr = X;

        for (int j = 0; j < Y; ++j) {
            cin >> x_i >> x_j;

            Union(x_i, x_j);
        }

        cout << ctr << " ";
    }
    return 0;
}
