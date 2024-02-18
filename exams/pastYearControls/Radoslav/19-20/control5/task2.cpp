#include <cmath>
#include<climits>
#include<queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& distances, int start, int k, int n) {
    queue<pair<int, int>> q;
    vector<bool> visited(n + 1);
    visited[start] = true;
    distances[start] = 0;
    for (int i = 1; i <= n; i++) {
        distances[i] = INT_MAX;
    }
    q.push({ start,0 });
    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist == k) {
            distances[node] = 1;
        }
        for (auto& el : graph[node]) {
            if (!visited[el]) {
                visited[el] = true;
                q.push({ el,dist + 1 });
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    bool flag = false;
    vector<int> distances(n + 1);
    bfs(graph, distances, n, k, n);
    for (int i = 1; i <= n; i++) {
        if (distances[i] == 1) {
            cout << i << " ";
            flag = true;
        }
    }

    if (!flag) {
        cout << -1;
    }
    return 0;
}