#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V, E, K, x, y, w;
vector<vector<pair<int, int>>> adj;
vector<int> path;

int isThereWay(int from, int to) {
    for (auto n : adj[from]) {
        if (n.first == to) {
            return n.second;
        }
    }

    return -1;
}

int main() {
    cin >> V >> E;

    adj = vector<vector<pair<int, int>>>(V, vector<pair<int, int>>());

    for (int i = 0; i < E; ++i) {
        cin >> x >> y >> w;

        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    cin >> K;

    path = vector<int>(K);

    for (int i = 0; i < K; ++i) {
        cin >> path[i];
    }

    int ctr = 0;
    int curRes = 0;

    for (int i = 0; i < K - 1; ++i) {
        curRes = isThereWay(path[i], path[i + 1]);

        if (curRes == -1) {
            ctr = -1;
            break;
        }

        ctr += curRes;
    }

    cout << ctr;

    return 0;
}
