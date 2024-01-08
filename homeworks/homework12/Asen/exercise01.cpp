#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, y, typeQ, Q;
const int MAX = 1000000;

int parents[MAX], depth[MAX];

int Find(int v) {
    if (v == parents[v]) {
        return v;
    }

    return parents[v] = Find(parents[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }

        parents[b] = a;

        if (depth[a] == depth[b]) {
            depth[a]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        parents[i] = i;
    }

    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        Union(x, y);
    }

    cin >> Q;

    for (int i = 0; i < Q; ++ i) {
        cin >> typeQ >> x >> y;

        if (typeQ == 1) {
            bool areEqual = Find(x) == Find(y);
            cout << areEqual;
        } else if (typeQ == 2) {
            Union(x, y);
        }
    }
}
