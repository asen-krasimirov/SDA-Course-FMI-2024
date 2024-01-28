#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll V, E, x, y, w;
vector<pair<ll, pair<ll, ll>>> edges;

const ll MAX = 1e6;

ll parents[MAX], depth[MAX];

ll Find(ll a) {
    if (a == parents[a]) {
        return a;
    }

    return parents[a] = Find(parents[a]);
}

void Union(ll a, ll b) {
    a = Find(a);
    b = Find(b);

    if (a == b) {
        return;
    }

    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    parents[b] = a;

    if (depth[a] == depth[b]) {
        depth[a]++;
    }
}

ll kruskal() {
    sort(edges.begin(), edges.end(), greater<>());

    ll minCutOut = 0;

    for (auto edge : edges) {
        ll a = edge.second.first;
        ll b = edge.second.second;

        if (Find(a) != Find(b)) {
            minCutOut += edge.first;
            Union(a, b);
        }
    }

    return minCutOut;
}

int main() {
    cin >> V >> E;

    for (int i = 0; i < V; ++i) {
        parents[i] = i;
        depth[i] = 0;
    }

    ll totalSum = 0;

    for (int i = 0; i < E; ++i) {
        cin >> x >> y >> w;

        edges.push_back({ w, { x, y }});
        edges.push_back({ w, { y, x }});
        totalSum += w;
    }

    ll res = kruskal();

    cout << totalSum - res;

    return 0;
}
