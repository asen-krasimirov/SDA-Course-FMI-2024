#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V, E, x, y, K;

int parents[1000001], depth[1000001];

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

    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    parents[b] = a;

    if (depth[a] == depth[b]) {
        depth[a]++;
    }
}

int main() {
    cin >> V >> E;

    for (int i = 1; i <= V; ++i) {
        parents[i] = i;
    }

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;
        Union(x, y);
    }

    cin >> K;

    while (K--) {
        cin >> x >> y;

        bool res = parents[x] == parents[y];

        cout << res << " ";
    }

    return 0;
}
