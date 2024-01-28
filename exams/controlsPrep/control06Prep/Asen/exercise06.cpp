#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

#include <queue>

using namespace std;

/* not full points solution */

int V, E, x, y, S;
vector<vector<int>> adj;
vector<bool> stops;
vector<int> path;

vector<bool> visited;

int bfs(int from, int to) {
    visited[from] = true;
    queue<pair<int, int>> q;

    q.push({ from, 0 });

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node == to) {
            return dist;
        }

        visited[node] = true;

        for (auto n : adj[node]) {
            if (!visited[n] && (stops[n] == -1 || n == to)) {
                visited[n] = true;
                q.push({ n, dist+ 1 });
            }
        }
    }

    return -1;
}


int main() {
    cin >> V >> E;

    adj = vector<vector<int>>(V);
    visited = vector<bool>(V, false);

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;

        adj[x].push_back(y);
    }

    cin >> S;

    stops = vector<bool>(V, false);

    for (int i = 0; i < S; ++i) {
        int stop;
        cin >> stop;
        path.push_back(stop);

        stops[stop] = true;
    }

    stops[path[0]] = -1;

    int res = 0;

    for (int i = 0; i < S - 1; ++i) {
        int from = path[i];
        int to = path[i + 1];

        int curRes = bfs(from, to);

        if (curRes == -1) {
            cout << -1;
            return 0;
        }

        res += curRes;
    }

    cout << res;

    return 0;
}
