#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T, V, E, ctr, x, y;
const int MAX_V = 100001;
int parents[MAX_V], depth[MAX_V];

int Find(int a) {
    if (a == parents[a]) {
        return a;
    }

    return parents[a] = Find(parents[a]);
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

    while (T--) {
        cin >> V >> E;

        for (int i = 0; i < V; ++i) {
            parents[i] = i;
            depth[i] = 0;
        }

        ctr = V;

        while (E--) {
            cin >> x >> y;

            Union(x, y);
        }

        cout << ctr << " ";
    }
    return 0;
}
