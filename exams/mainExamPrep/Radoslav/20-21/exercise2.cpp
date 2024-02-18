#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& components, int node, int& component, vector<bool>& visited) {
    visited[node] = true;
    components[node] = component;
    for (auto& el : graph[node]) {
        if (!visited[el]) {
            dfs(graph, components, el, component, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> components(n + 1, 0);
    int component = 1;
    vector<bool> visited(n + 1, false);
    for (int i = 0; i <= n; i++) {
        if (!visited[i]) {
            dfs(graph, components, i, component, visited);
            component++;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << (components[x] == components[y]) << " ";
    }
    return 0;
}