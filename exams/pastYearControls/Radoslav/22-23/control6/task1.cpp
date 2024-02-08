#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, int current, vector<bool>& visited) {
    visited[current] = true;

    for (auto& n : graph[current]) {
        if (!visited[n]) {
            dfs(graph, n, visited);
        }
    }
}


int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for (int j = 0; j < m; j++) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        int components = 0;
        vector<bool> visited(n + 1);
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                dfs(graph, j, visited);
                components++;
            }
        }
        cout << components << " ";
    }
}


