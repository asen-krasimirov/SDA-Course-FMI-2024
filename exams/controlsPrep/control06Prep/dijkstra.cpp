#pragma once

#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(101);
int distTo[101];

void dijkstra(int s) {
    distTo[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int v = pq.top().second;
        int v_dist = pq.top().first;
        pq.pop();

        if (distTo[v] != v_dist) {
            continue;
        }

        for (auto n : adj[v]) {
            int w = n.first;        // cost and value are swapped in adj
            int w_dist = n.second;

            if (distTo[w] > w_dist + v_dist) {
                distTo[w] = w_dist + v_dist;
                pq.push({ distTo[w], w });
            }
        }
    }
}

int main() {
    dijkstra(0);

    return 0;
}