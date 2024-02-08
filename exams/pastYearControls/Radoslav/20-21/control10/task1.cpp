#include <queue>
#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int to, weight;
    bool operator>(const Edge& other)const {
        return weight > other.weight;
    }
};

void dijkstra(vector<vector<Edge>>& graph, vector<int>& distances, int start) {
    //visited[start] = true;
    distances[start] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({ start,0 });

    while (!pq.empty()) {
        int node = pq.top().to;
        int dist = pq.top().weight;
        pq.pop();
        if (distances[node] < dist) {
            continue;
        }
        for (auto& n : graph[node]) {
            int next = n.to;
            int nextD = n.weight;
            int totalDist = dist + nextD;

            if (totalDist < distances[next]) {
                distances[next] = totalDist;
                pq.push({ next,totalDist });
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to,weight });
        graph[to].push_back({ from,weight });
    }
    vector<int> distances(n + 1);
    for (int i = 0; i <= n; i++) {
        distances[i] = INT_MAX;
    }
    vector<bool> visited(n + 1, false);
    int start;
    cin >> start;
    dijkstra(graph, distances, start);

    for (int i = 1; i <= n; i++) {
        if (i != start) {
            if (distances[i] != INT_MAX) {
                cout << distances[i] << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
    }

    return 0;
}