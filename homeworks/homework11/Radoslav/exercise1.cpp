#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int destination;
    int weight;

    bool operator>(const Node& other) const {
        return this->weight > other.weight;
    }
};

void djikstra(vector<int>& distances, vector<vector<Node>>& g, int start, vector<int>& waitingTimes) {
    distances[start] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({ start,0 });

    while (!pq.empty()) {
        int currentNode = pq.top().destination;
        int currentWeight = pq.top().weight;
        pq.pop();

        if (currentWeight > distances[currentNode]) {
            continue;
        }

        for (auto& n : g[currentNode]) {
            int nextNode = n.destination;
            int dist = n.weight;
            int total = dist + currentWeight;
            if (currentWeight % waitingTimes[currentNode] != 0) {
                total += (waitingTimes[currentNode] - currentWeight % waitingTimes[currentNode]);
            }
            

            if (distances[nextNode] > total) {
                distances[nextNode] = total;
                pq.push({ nextNode,total });
            }
        }
    }
}


int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<Node>> g(n + 1);
    vector<int> waitingTimes(n+1);
    for (int i = 0; i < n; i++) {
        cin >> waitingTimes[i];
    }
    for (int i = 0; i < m; i++) {
        int to, dest, weight;
        cin >> to >> dest >> weight;
        g[to].push_back({ dest,weight });
    }
    vector<int> distances(n + 1);
    for (int i = 0; i < n; i++) {
        distances[i] = INT_MAX;
    }
    djikstra(distances, g, s, waitingTimes);

    if (distances[e] != INT_MAX) {
        cout << distances[e];
    }
    else {
        cout << -1;
    }
    return 0;
}
