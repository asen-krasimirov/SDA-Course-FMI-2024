#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V, E, x, y, w, N;
vector<vector<pair<int, int>>> adj;

int getW(int a, int b) {
    for (auto n : adj[a]) {
        if (n.first == b) {
            return n.second;
        }
    }

    return -1;
}

int main() {
    cin >> V >> E;

    adj = vector<vector<pair<int, int>>>(V);

    for (int i = 0; i < E; ++i) {
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    cin >> N;

    vector<int> path(N);

    for (int i = 0; i < N; ++i) {
        cin >> path[i];
    }

    int prev = path[0];
    int cur;
    int curRes;
    int res = 0;

    for (int i = 1; i < N; ++i) {
        cur = path[i];

        curRes = getW(prev, cur);

        if (curRes == -1) {
            res = -1;
            break;
        }

        res += curRes;
        prev = cur;
    }

    cout << res;

    return 0;
}
