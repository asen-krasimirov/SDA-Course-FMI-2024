#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_set>
#include <queue>

using namespace std;

typedef long long ll;

ll V, E, K, x, y;
ll INF = 1e9;
vector<vector<ll>> adj;
vector<ll> path;
unordered_set<ll> yetToSee;

ll findShortestPath(ll s, ll to) {
    vector<bool> visited(V, false);
    vector<int> distTo(V, INF);

    queue<ll> q;
    q.push(s);
    visited[s] = true;
    distTo[s] = 0;

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (auto n : adj[cur]) {
            if (yetToSee.find(n) != yetToSee.end()) {
                continue;
            }

            int new_d = distTo[cur] + 1;

            if (new_d < distTo[n]) {
                distTo[n] = new_d;
            }

            if (n == to) {
                return distTo[n];
            }

            if (!visited[n]) {
                q.push(n);
                visited[n] = true;
            }
        }
    }

    return -1;
}

int main() {
    cin >> V >> E;

    adj = vector<vector<ll>>(V, vector<ll>());

    for (ll i = 0; i < E; ++i) {
        cin >> x >> y;

        adj[x].push_back(y);
    }

    cin >> K;

    path = vector<ll>(K);

    for (ll i = 0; i < K; ++i) {
        cin >> path[i];
        yetToSee.insert(path[i]);
    }

    ll ctr = 0;
    ll curRes = 0;

    for (ll i = 0; i < K - 1; ++i) {
        yetToSee.erase(path[i]);
        yetToSee.erase(path[i + 1]);

        curRes = findShortestPath(path[i], path[i + 1]);

        if (curRes == -1) {
            ctr = -1;
            break;
        }

        ctr += curRes;
    }

    cout << ctr;

    return 0;
}
