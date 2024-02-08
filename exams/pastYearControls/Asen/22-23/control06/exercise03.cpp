#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T, V, E, x, y, w;
bool hasCycle;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int v) {
    visited[v] = 1;

    for (auto n : adj[v]) {
        if (visited[n] == 1) {
            hasCycle = true;
            return;
        }

        if (visited[n] == 0) {
            dfs(n);
        } else {
            continue;
        }

        if (hasCycle) {
            return;
        }
    }

    visited[v] = 2;
}

void traverse() {
    hasCycle = false;

    for (int i = 1; i <= V; ++i) {
        if (visited[i] == 0) {
            dfs(i);

            if (hasCycle) {
                return;
            }
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        cin >> V >> E;

        adj = vector<vector<int>>(V + 1);
        visited = vector<int>(V + 1);

        for (int i = 0; i < E; ++i) {
            cin >> x >> y >> w;
            adj[x].push_back(y);
        }

        traverse();

        if (hasCycle) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    return 0;
}
