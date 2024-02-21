#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V, E, K, x, y, curCtr = 0, ctr = 0;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int v) {
    int ctr = 1;
    visited[v] = true;

    for (auto n : adj[v]) {
        if (!visited[n]) {
            ctr += dfs(n);
        }
    }

    return ctr;
}

void getCount() {
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            curCtr = dfs(i);

            if (curCtr % K == 0) {
                ctr++;
            }
        }
    }
}

int main() {
    cin >> V >> E >> K;

    adj = vector<vector<int>>(V);
    visited = vector<bool>(V, false);

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    getCount();

    cout << ctr;

    return 0;
}
