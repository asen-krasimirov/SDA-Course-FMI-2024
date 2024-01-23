#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

ll N, M, x, y, w;
vector<vector<pair<ll, ll>>> adj;
//vector<ll> distTo;
vector<pair<ll, ll>> distTo;
const ll INF = 1000000007;

void dijkstra(ll s) {
//    distTo[s] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    pq.push({ 0, s });
    distTo[s] = { 1, 0 };

    while (!pq.empty()) {
        ll v_d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();

        if (v_d != distTo[v].second) {
            continue;
        }

        for (auto n : adj[v]) {
            ll w_d = n.first;
            ll w = n.second;

            ll new_d = v_d + w_d % INF;

            if (distTo[w].second > new_d) {
                distTo[w].second = new_d;
                distTo[w].first = distTo[v].first;

                pq.push({ new_d, w });
            } else if (distTo[w].second == new_d) {
                distTo[w].first =  (distTo[w].first + distTo[v].first) % INF;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    N++;

    adj = vector<vector<pair<ll, ll>>>(N, vector<pair<ll, ll>>());
    distTo = vector<pair<ll, ll>>(N, { 0, LONG_MAX });

    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> w;
        adj[x].push_back({ w, y });
    }

    dijkstra(1);

    N--;
    ll res = distTo[N].second;

    if (res != LONG_MAX) {
        cout << res;
    } else {
        cout << -1;
    }

    cout << " " << distTo[N].first;

    return 0;
}
