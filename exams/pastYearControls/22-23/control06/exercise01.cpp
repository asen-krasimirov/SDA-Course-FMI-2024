#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T, V, E, x, y, ctr;
int parents[100001], depth[100001];

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

        ctr = V;

        for (int i = 0; i < V; ++i) {
            parents[i] = i;
            depth[i] = 0;
        }

        for (int i = 0; i < E; ++i) {
            cin >> x >> y;
            Union(x, y);
        }

        cout << ctr << " ";
    }

    return 0;
}
