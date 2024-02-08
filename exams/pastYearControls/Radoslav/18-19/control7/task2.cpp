#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

struct Node {
    int to, weight;
};

void bfs(unordered_map<int, vector<Node>>& graph, unordered_map<int, int>& paths, int k, int start, int n) {
    vector<bool> visited(n + 1, false);
    queue<pair<pair<int, int>, int>> q;
    q.push({ {start,0},0 });
    visited[start] = true;

    while (!q.empty()) {
        int currentNode = q.front().first.first;
        int dist = q.front().first.second;
        int edges = q.front().second;
        q.pop();
        if (edges == k) {
            paths[dist]++;
            continue;
        }

        for (auto& n : graph[currentNode]) {
            if (!visited[n.to]) {
                q.push({ {n.to,dist + n.weight},edges + 1 });
            }
        }

    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Node>> graph;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to,weight });
    }
    int k;
    cin >> k;
    unordered_map<int, int> paths;
    for (int i = 0; i <= n; i++) {
        bfs(graph, paths, k, i, n);
    }
    long long result = -1, max = 0;
    for (const auto& element : paths) {
        if (element.second > max || (element.second == max && element.first > result)) {
            max = element.second;
            result = element.first;
        }
    }
    cout << result;
    return 0;
}



