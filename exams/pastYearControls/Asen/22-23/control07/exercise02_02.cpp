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

vector<ll> distTo;

const ll INF = 1000000000000000;

ll findPath(ll a, ll b) {
    distTo = vector<ll>(V, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({ 0, a});
    distTo[a] = 0;

    while (!pq.empty()) {
        a = pq.top().second;
        ll a_d = pq.top().first;
        pq.pop();

        if (a_d != distTo[a]) {
            continue;
        }

        for (auto n : adj[a]) {
            if (notYet.find(n) != notYet.end()) {
                continue;
            }

            ll new_d = a_d + 1;

            if (new_d < distTo[n]) {
                distTo[n] = new_d;
                pq.push({new_d, n});
            }
        }

    }

    if (distTo[b] != INF) {
        return distTo[b];
    } else {
        return -1;
    }
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
