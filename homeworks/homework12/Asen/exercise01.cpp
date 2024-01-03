#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, y, typeQ, Q;
const int MAX = 1000000;

int parent[MAX], depth[MAX];

int Find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int root1 = Find(x);
    int root2 = Find(y);
    if(root1 == root2) {
        return;
    }
    if(depth[root1] > depth[root2])
        swap(root1, root2);
    if(depth[root1] == depth[root2]) {
        depth[root2]++;
    }
    parent[root1] = root2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        parent[i] = i;
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
