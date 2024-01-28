#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Union-Find

int parents[101], depth[101];

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

void kruskal(int v, int e, vector<pair<int, pair<int, int>>> &edges) {
    for (int i = 0; i < v; ++i) {
        parents[i] = i;
        depth[i] = 1;
    }

    sort(edges.begin(), edges.end());

    for (auto edge : edges) {
        Union(edge.second.first, edge.second.second);
    }
}