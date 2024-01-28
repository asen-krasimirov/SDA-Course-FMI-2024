#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, int& members, vector<bool>& visited, int node) {
    visited[node] = true;
    for (auto el : graph[node]) {
        if (!visited[el]) {
            members++;
            dfs(graph, members, visited, el);
        }
    }
}

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector<vector<int>> graph(n);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int members = 1;
            dfs(graph, members, visited, i);
            if (members % k) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}