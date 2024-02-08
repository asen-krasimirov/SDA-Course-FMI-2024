#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    for (auto& el : graph[node]) {
        if (!visited[el]) {
            dfs(graph, el, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    unordered_set<int> vertices;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        vertices.insert(from);
        vertices.insert(to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int components = 0;
    vector<bool> visited(n + 1);
    for (int i = 0; i < n; i++) {
        if (vertices.find(i) != vertices.end()) {
            if (!visited[i]) {
                dfs(graph, i, visited);
                components++;
            }
        }
    }
    cout << components;
    return 0;
}