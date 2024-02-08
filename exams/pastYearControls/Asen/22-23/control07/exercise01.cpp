#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// #include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 55.56 / 100

typedef long long ll;

ll N, x, y, K;
vector<vector<ll>> matrix;
unordered_map<ll, unordered_set<ll>> jumps;
vector<vector<ll>> distTo;

const ll MIN = -100000000000000;

bool isValid(ll a, ll b) {
    return a >= 0 && a < N && b >= 0 && b < N;
}

void dijkstra() {
    priority_queue<pair<ll, pair<ll, ll>>> pq;

    pq.push({ matrix[0][0], {0, 0} });
    distTo[0][0] = matrix[0][0];

    while (!pq.empty()) {
        ll a = pq.top().second.first;
        ll b = pq.top().second.second;
        ll d_v = pq.top().first;
        pq.pop();

        if (d_v != distTo[a][b]) {
            continue;
        }

        if (isValid(a, b + 1)) {
            if (matrix[a][b + 1] + d_v > distTo[a][b + 1]) {
                distTo[a][b + 1] = matrix[a][b + 1] + d_v;
                pq.push({ distTo[a][b + 1], { a, b + 1 } });
            }
        }

        if (isValid(a + 1, b)) {
            if (matrix[a + 1][b] + d_v > distTo[a + 1][b]) {
                distTo[a + 1][b] = matrix[a + 1][b] + d_v;
                pq.push({ distTo[a + 1][b], { a + 1, b } });
            }
        }

        // if (jumps.find({ a + 1, b + 1 }) != jumps.end()) {
        if (jumps[a + 1].find(b + 1) != jumps[a + 1].end()) {
            if (matrix[a + 1][b + 1] + d_v > distTo[a + 1][b + 1]) {
                distTo[a + 1][b + 1] = matrix[a + 1][b + 1] + d_v;
                pq.push({ distTo[a + 1][b + 1], { a + 1, b + 1 } });
            }
        }
    }
}

int main() {
    cin >> N;

    matrix = vector<vector<ll>>(N);
    distTo = vector<vector<ll>>(N, vector<ll>(N, MIN));

    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            cin >> x;
            matrix[i].push_back(x);
        }
    }

    cin >> K;

    for (ll i = 0; i < K; ++i) {
        cin >> x >> y;
        // jumps.insert({ x, y });
        jumps[x].insert(y);
    }

    dijkstra();

    cout << distTo[N - 1][N - 1];

    return 0;
}
