#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, int& sum, int node) {
    for (auto el : graph[node]) {
        sum += el;
        dfs(graph, sum, el);
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> graph(1000000);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for (int i = 0; i < t; i++) {
        int node;
        cin >> node;
        int sum = 0;
        dfs(graph, sum, node);
        cout << sum << "\n";
    }
    return 0;
}