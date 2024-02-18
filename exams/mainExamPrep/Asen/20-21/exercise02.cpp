#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V, E, x, y, K;
const int MAX = 1e7 + 1;
int parents[MAX], depth[MAX];

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

    for (int i = 0; i < V; ++i) {
        parents[i] = i;
        depth[i] = 0;
    }

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;
        Union(x, y);
    }

    cin >> K;

    while (K--) {
        cin >> x >> y;

        bool i = Find(x) == Find(y);

        cout << i << " ";
    }

    return 0;
}
