#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V, E, x, y, Q;
const int MAX_V = 1000001;
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

    for (int i = 0; i < MAX_V; ++i) {
        parents[i] = i;
        depth[i] = 0;
    }

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;

        Union(x, y);
    }

    cin >> Q;

    while (Q--) {
        cin >> x >> y;

        bool res = Find(x) == Find(y);

        cout << res << " ";
    }

    return 0;
}
