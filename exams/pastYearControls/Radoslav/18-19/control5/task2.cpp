#include <cmath>
#include <queue>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>>& graph, int start, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,start });
    distances[start] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (distances[node] < dist) {
            continue;
        }
        for (auto& el : graph[node]) {
            int nextNode = el;
            int nextDist = dist + 1;
            if (distances[nextNode] > nextDist) {
                distances[nextNode] = nextDist;
                pq.push({ nextDist,nextNode });
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vector<int> distances(n + 1);
    for (int i = 0; i <= n; i++) {
        distances[i] = INT_MAX;
    }
    bfs(graph, 0, distances);
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        if (distances[i] != INT_MAX) {
            sum += distances[i];
        }
    }
    cout << sum;
    return 0;
}