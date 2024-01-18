#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, V, E, x, y, w;

vector<vector<int>> adj;
vector<int> visited;

bool hasCycle(int v) {
    visited[v] = 1;

    for (int n : adj[v]) {
        if (visited[n] == 1) {
            return true;
        }

        if (visited[n] == 2) {
            continue;
        }

        if (hasCycle(n)) {
            return true;
        }
    }

    visited[v] = 2;

    return false;
}

bool dfs() {
    for (int i = 1; i < V; ++i) {
        if (visited[i] != 2 && hasCycle(i)) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> N;

    while (N--) {
        cin >> V >> E;
        V++;

        adj = vector<vector<int>>(V, vector<int>());
        visited = vector<int>(V, 0);

        for (int i = 0; i < E; ++i) {
            cin >> x >> y >> w;

            adj[x].push_back(y);
        }

        bool res = dfs();

        if (res) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }

    return 0;
}
