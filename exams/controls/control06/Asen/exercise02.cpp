#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

/* 38.89/100 solution */

size_t INF = 1000000007;

size_t N, M, x, y, c;

void dijkstra(size_t s, vector<vector<pair<size_t, size_t>>> &adj, vector<size_t> &distTo) {
    distTo[s] = 0;

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<>> pq;
    pq.push({ 0, s });

    while (!pq.empty()) {
        size_t v = pq.top().second;
        size_t v_d = pq.top().first;
        pq.pop();

        if (v_d != distTo[v]) {
            continue;
        }

        for (auto &e : adj[v]) {
            size_t w_d = e.first;
            size_t w = e.second;

            size_t new_d = v_d + w_d;

            if (new_d <= distTo[w]) {
                distTo[w] = new_d;
                pq.push({ distTo[w], w });
            }

        }
    }
}

int main() {
    cin >> N >> M;
    N++;

    vector<vector<pair<size_t, size_t>>> adj = vector<vector<pair<size_t, size_t>>>(N, vector<pair<size_t, size_t>>());
    vector<size_t> distTo = vector<size_t>(N, INF);

    for (size_t i = 0; i < M; ++i) {
        cin >> x >> y >> c;

        adj[x].push_back({ c, y });
    }

    dijkstra(1, adj, distTo);

    N--;

    size_t res = distTo[N];

    if (res == INF) {
        cout << -1 << " " << 0;
    } else {
        cout << res << " " << 1;
    }

    return 0;
}
