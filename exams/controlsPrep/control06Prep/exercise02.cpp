#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, y, w, K;
vector<int> *adj;

int main() {
    cin >> N >> M;

    adj = new vector<int>[N];

    for (int i = 0; i < N; ++i) {
        adj[i] = vector<int>(N, -1);
    }

    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> w;

        adj[x][y] = w;
        adj[y][x] = w;
    }

    cin >> K;
    int cost = 0;
    int prev = -1;

    for (int i = 0; i < K; ++i) {
        cin >> x;

        if (prev == -1) {
            prev = x;
            continue;
        }

        int curCost = adj[prev][x];

        if (curCost == -1) {
            cost = -1;
            break;
        }

        cost += curCost;
        prev = x;
    }

    cout << cost;

    return 0;
}
