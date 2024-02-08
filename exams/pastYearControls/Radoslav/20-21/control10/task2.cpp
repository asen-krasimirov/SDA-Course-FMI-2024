#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Edge {
    int to, weight;
};

void dfs(vector<vector<Edge>>& graph, int node, int k, int count, int sum, vector<bool>& visited, unordered_map<int, int>& paths) {
    if (count == k) {
        paths[sum]++;
        return;
    }
    visited[node] = true;
    for (auto& el : graph[node]) {
        if (!visited[el.to]) {
            dfs(graph, el.to, k, count + 1, sum + el.weight, visited, paths);
        }
    }
    visited[node] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> paths;
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to,weight });
    }
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1);
        int count = 0;
        int sum = 0;
        dfs(graph, i, k, count, sum, visited, paths);
    }
    int maxPath = 0;
    int maxCount = 0;

    if (paths.empty()) {
        cout << -1;
        return 0;
    }

    for (auto& el : paths) {
        if (el.second == maxCount ? el.first > maxPath : el.second > maxCount) {
            maxPath = el.first;
            maxCount = el.second;
        }
    }
    cout << maxPath;
    return 0;
}