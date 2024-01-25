#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_set>

using namespace std;

typedef long long ll;

ll V, E, x, y, w, K, T, L;
vector<vector<pair<ll, ll>>> adj;
unordered_set<ll> noNums;

bool isPath(ll a, ll b) {
    for (auto n : adj[a]) {
        if (n.first == b && noNums.find(n.second) == noNums.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> V >> E;

    adj = vector<vector<pair<ll, ll>>>(V);

    for (ll i = 0; i < E; ++i) {
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
    }

    cin >> K;

    for (ll i = 0; i < K; ++i) {
        cin >> x;
        noNums.insert(x);
    }

    cin >> T;

    while (T--) {
        cin >> L;

        vector<ll> path(L);

        for (int i = 0; i < L; ++i) {
            cin >> path[i];
        }

        bool res = true;

        for (int i = 0; i < L - 1; ++i) {
            x = path[i];
            y = path[i + 1];

            res = isPath(x, y);

            if (!res) {
                break;
            }

        }

        cout << res;
    }

    return 0;
}
