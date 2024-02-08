#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V, E, x, y;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> children;

int maxCutOut = 0;

int dfs(int v) {
    visited[v] = true;
    int ctr = 1;

    for (auto n : adj[v]) {
        if (!visited[n]) {
            children[n] += dfs(n);

            if (children[n] % 2 == 0) {
                maxCutOut++;
            } else {
                ctr += children[n];
            }
        }
    }

    return ctr;
}

void countChildren() {
    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) {
            children[i] += dfs(i);
        }
    }
}

int main() {
    cin >> V >> E;

    adj = vector<vector<int>>(V + 1);
    visited = vector<bool>(V + 1, false);
    children = vector<int>(V + 1);

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    countChildren();

    cout << maxCutOut;

    return 0;
}
