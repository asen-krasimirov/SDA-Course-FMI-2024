#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>>& graph, int from, int target, unordered_set<int>& pathRoute) {
    int res = 0;
    queue<pair<int, int>> q;
    vector<bool> visited(graph.size() + 1);
    visited[from] = true;
    q.push({ from,0 });

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node == target) {
            return dist;
        }

        for (auto& el : graph[node]) {
            if (!visited[el] && (pathRoute.find(el) == pathRoute.end() || el == target)) {
                visited[el] = true;
                q.push({ el,dist + 1 });
            }
        }
    }

    return -1;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
    }

    int k;
    cin >> k;
    unordered_set<int> pathRoute;
    vector<int> path(k);
    for (int i = 0; i < k; i++) {
        cin >> path[i];
        pathRoute.insert(path[i]);
    }

    int ans = 0;
    pathRoute.erase(path[0]);
    for (int i = 0; i < k - 1; i++) {
        pathRoute.erase(path[i + 1]);
        int from = path[i];
        int to = path[i + 1];
        int result = bfs(g, from, to, pathRoute);
        if (result != -1) {
            ans += result;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    cout << ans;

    return 0;
}


