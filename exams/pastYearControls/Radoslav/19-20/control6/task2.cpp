#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int& result) {
    visited[node] = true;
    int totalCount = 1;
    for (auto& el : graph[node]) {
        if (!visited[el]) {
            size_t count = dfs(graph, visited, el, result);
            if (!(count & 1) && count != 0) {
                result++;
            }
            else {
                totalCount += count;
            }
        }
    }
    return totalCount;
}


int main() {
    int n, m;
    cin >> n >> m;
    int start;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        start = from;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int result = 0;
    vector<bool> visited(n + 1, false);
    dfs(graph, visited, start, result);
    cout << result;
    return 0;
}

