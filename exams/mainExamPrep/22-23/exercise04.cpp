#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

int V, E, x, y, P, K;
vector<vector<int>> adj;
// vector<bool> visited;
vector<int> distTo;

unordered_set<int> forbidden;
unordered_set<int> notYet;
vector<int> path;

int dijkstra(int from, int to) {
    // visited = vector<bool>(V, false);
    distTo = vector<int>(V, INT_MAX);

    priority_queue<pair<int, int>> pq;
    pq.push({0, from});
    distTo[from] = 0;

    while (!pq.empty()) {
        int d_v = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d_v != distTo[v]) {
            continue;
        }

        for (auto n : adj[v]) {
            if (notYet.find(n) != notYet.end() || forbidden.find(n) != forbidden.end()) {
                continue;
            }

            int new_d = d_v + 1;

            if (new_d < distTo[n]) {
                distTo[n] = new_d;
                pq.push({new_d, n});
            }
        }
    }

    if (distTo[to] == INT_MAX) {
        return -1;
    } else {
        return distTo[to];
    }
}

int main() {
    cin >> V >> E;

    adj = vector<vector<int>>(V);

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cin >> P;

    path = vector<int>(P);

    for (int i = 0; i < P; ++i) {
        cin >> path[i];
        notYet.insert(path[i]);
    }

    cin >> K;

    for (int i = 0; i < K; ++i) {
        cin >> x;
        notYet.insert(x);
    }

    int prev, cur, curRes, res = 0;

    for (int i = 0; i < P - 1; ++i) {
        prev = path[i];
        cur = path[i + 1];

        notYet.erase(prev);
        notYet.erase(cur);

        curRes = dijkstra(prev, cur);

        if (curRes == -1) {
            res = -1;
            break;
        }

        res += curRes;
    }

    cout << res;

    return 0;
}
