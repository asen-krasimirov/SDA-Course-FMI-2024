#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>
#include <unordered_set>

using namespace std;

typedef long long ll;

ll V, E, x, y, K;
vector<vector<ll>> adj;

vector<ll> path;
unordered_set<ll> notYet;
vector<bool> visited;

ll findPath(ll a, ll b) {
    visited = vector<bool>(V, false);
    queue<pair<int, int>> q;

    q.push({ 0, a });
    visited[a] = true;

    while (!q.empty()) {
        a = q.front().second;
        ll a_d = q.front().first;
        q.pop();

        if (a == b) {
            return a_d;
        }

        for (auto n : adj[a]) {
            if (notYet.find(n) != notYet.end()) {
                continue;
            }

            if (!visited[n]) {
                q.push({ a_d + 1, n });
            }
        }
    }

    return -1;
}

int main() {
    cin >> V >> E;

    adj = vector<vector<ll>>(V);

    for (ll i = 0; i < E; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cin >> K;

    path = vector<ll>(K);

    for (ll i = 0; i < K; ++i) {
        cin >> path[i];
        notYet.insert(path[i]);
    }

    ll prev, cur;
    ll curRes, res = 0;

    if (K > 0) {
        prev = path[0];
    }

    for (ll i  = 1; i < K; ++i) {
        cur = path[i];

        notYet.erase(prev);
        notYet.erase(cur);

        curRes = findPath(prev, cur);

        if (curRes == -1) {
            res = -1;
            break;
        }

        res += curRes;
        prev = cur;
    }

    cout << res;

    return 0;
}
