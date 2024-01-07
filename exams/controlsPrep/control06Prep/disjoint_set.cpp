#include <iostream>

int parents[101], depth[101];

int Find(int n) {
    if (n == parents[n]) {
        return n;
    }

    return parents[n] = Find(n);
}

int Union(int v, int w) {
    v = Find(v);
    w = Find(w);

    if (v != w) {
        if (depth[v] < depth[w]) {
            std::swap(v, w);
        }

        parents[w] = v;

        if (depth[v] == depth[w]) {
            depth[v]++;
        }
    }
}
