#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int to, weight;

    bool operator>(const Node& other)const {
        return weight > other.weight;
    }
};

void dijkstra(unordered_map<int, vector<Node>>& g, int start, vector<int>& distances) {
    distances[start] = 0;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({ start,0 });

    while (!pq.empty()) {
        int currentNode = pq.top().to;
        int dist = pq.top().weight;
        pq.pop();
        if (dist > distances[currentNode]) {
            continue;
        }

        for (auto& el : g[currentNode]) {
            int nextNode = el.to;
            int nestDist = el.weight;
            int totalDistance = dist + nestDist;

            if (distances[nextNode] > totalDistance) {
                distances[nextNode] = totalDistance;
                pq.push({ nextNode,totalDistance });
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Node>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        g[from].push_back({ to,weight });
        g[to].push_back({ from,weight });
    }
    int start;
    cin >> start;
    vector<int> distances(n + 1);
    for (int i = 0; i <= n; i++) {
        distances[i] = INT_MAX;
    }
    dijkstra(g, start, distances);

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