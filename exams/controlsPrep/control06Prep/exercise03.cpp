#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <set>

using namespace std;

int T, V, E, x, y, w;
vector<vector<int>> adj;
vector<bool> visited;
bool hasCycle;

void dfs(int v, set<int> &vals) {
    visited[v] = true;
    vals.insert(v);

    for (auto i : adj[v]) {
        // if (visited[i]) {
        // hasCycle = true;
        // return;
        // }

        if (hasCycle) {
            return;
        }

        if (vals.find(i) != vals.end()) {
            hasCycle = true;
            return;
        }

        if (!visited[i]) {
            dfs(i, vals);
        }

    }

    vals.erase(v);
}

void traverse() {
    set<int> vals;

    for (int i = 1; i <= V; ++i) {
        if (visited[i]) {
            continue;
        }

        dfs(i, vals);

        if (hasCycle) {
            break;
        }
    }
}


int main() {
    cin >> T;

    while (T--) {
        cin >> V >> E;
        hasCycle = false;

        adj = vector<vector<int>>(V + 1);
        visited = vector<bool>(V + 1);

        for (int i = 0; i < E; ++i) {
            cin >> x >> y >> w;

            adj[x].push_back(y);
        }

        traverse();

        if (hasCycle) {
            cout << "true" << " ";
        } else {
            cout << "false" << " ";
        }
    }

    return 0;
}
