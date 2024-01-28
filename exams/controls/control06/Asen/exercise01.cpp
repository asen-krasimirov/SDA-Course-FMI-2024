#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, x, y, ctr;

int parents[1000001], depth[1000001];

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
        cout << ctr << " " << "CYCLE FORMED!" << endl;
        return;
    }

    ctr--;

    cout << ctr << endl;

    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    parents[b] = a;

    if (depth[a] == depth[b]) {
        depth[a]++;
    }
}

int main() {
    cin >> N;
    ctr = N;

    for (int i = 1; i <= N; ++i) {
        parents[i] = i;
    }

    while (cin >> x >> y) {
        Union(x, y);
    }

    return 0;
}
