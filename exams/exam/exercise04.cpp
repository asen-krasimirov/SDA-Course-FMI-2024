#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;

const ll MAX_V = 1000001;

ll parents[MAX_V], depth[MAX_V];
vector<ll> nodes;
vector<ll> sums;

ll Find(ll a) {
    if (a == parents[a]) {
        return a;
    }

    return parents[a] = Find(parents[a]);
}

void Union(ll a, ll b, ll w) {
    a = Find(a);
    b = Find(b);

    if (a == b) {
        return;
    }

    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    parents[b] = a;

    nodes[a] += nodes[b] + 1;
    nodes[b] = 0;
    sums[a] += sums[b] + w;
    sums[b] = 0;

    if (depth[a] == depth[b]) {
        depth[a]++;
    }
}

ll kruskal(vector<pair<ll, pair<ll, ll>>> &edges, ll K, ll V) {
    sort(edges.begin(), edges.end());
    ll totalW = 0;

    for (auto e : edges) {
        ll w = e.first;
        ll x = e.second.first;
        ll y = e.second.second;

        Union(x, y, w);
    }

    for (ll i = 0; i < V; ++i) {
        if (nodes[i] == 0) {
            continue;
        }

        // cout << i << " " << nodes[i] + 1 << " " << sums[i] << endl;

        if ((nodes[i] + 1) % K == 0) {
            totalW += sums[i];
        }
    }

    return totalW;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll T, V, E, K, x, y, w;


    cin >> T;

    while (T--) {
        cin >> V >> E >> K;

        vector<pair<ll, pair<ll, ll>>> edges;
        nodes = vector<ll>(V, 0);
        sums = vector<ll>(V, 0);

        for (ll i = 0; i < V; ++i) {
            parents[i] = i;
            depth[i] = 0;
        }

        for (ll i = 0; i < E; ++i) {
            cin >> x >> y >> w;

            edges.push_back({ w, { x, y }});
        }

        cout << kruskal(edges, K, V) << endl;
    }

    return 0;
}
