#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;

void dfs(vector<bool>& visited, int current) {
    visited[current] = true;

    for (auto& el : graph[current]) {
        if (!visited[el]) {
            dfs(visited, el);
        }
    }
}


int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        int component = 0;
        vector<bool> visited(n + 1, false);
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                dfs(visited, j);
                component++;
            }
        }

        cout << component << " ";
        graph.clear();

    }
    return 0;
}

