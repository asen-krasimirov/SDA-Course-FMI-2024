#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T, X, Y, x, y, ctr;

int parents[100001], depth[100001];

int Find(int x) {
    if (x == parents[x]) {
        return x;
    }

    return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) {
        return;
    }

    ctr--;

    if (depth[x] < depth[y]) {
        swap(x, y);
    }

    parents[y] = x;

    if (x == y) {
        depth[x]++;
    }
}

int main() {
    cin >> T;

    while (T--) {
        cin >> X >> Y;

        for (int i = 0; i < X; ++i) {
            parents[i] = i;
            depth[i] = 0;
        }

        ctr = X;

        for (int i = 0; i < Y; ++i) {
            cin >> x >> y;

            Union(x, y);
        }

        cout << ctr << " ";
    }

    return 0;
}
