#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <climits>
#include <queue>

using namespace std;

int V, E, s, e;
vector<pair<int, int>> *adj;
int *distTo;
int *intervals;

void dijkstra(int s) {
    distTo[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();

        if (d_v != distTo[v]) {
            continue;
        }

        for (auto &edge : adj[v]) {
            int u = edge.second;
            int w_u = edge.first;

            int d_u = d_v + w_u;

            if (u != e && d_u % intervals[u] != 0) {
                d_u += intervals[u] - (d_u % intervals[u]);
            }

            if (d_u < distTo[u]) {
                distTo[u] = d_u;
                pq.push({ distTo[u], u });
            }
        }
    }
}

int main() {
    cin >> V >> E >> s >> e;

    adj = new vector<pair<int, int>>[V];
    distTo = new int[V];
    intervals = new int[V];

    for (int i = 0; i < V; ++i) {
        cin >> intervals[i];
        distTo[i] = INT_MAX;
    }

    int from, to, weight;
    for (int i = 0; i < E; ++i) {
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
    }

    dijkstra(s);

    if (distTo[e] != INT_MAX) {
        cout << distTo[e];
    } else {
        cout << -1;
    }

    return 0;
}
