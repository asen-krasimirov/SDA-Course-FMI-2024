#include <vector>
#include <climits>
#include <queue>

using namespace std;

/* Dijkstra algorithm solution */

class Solution {
public:
    vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(101);

    void dijkstra(int s, int *d) {
        d[s] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, s});

        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();

            if (d_v != d[v]) {
                continue;
            }

            for (auto edge : adj[v]) {
                if (d[edge.first] > edge.second + d_v) {
                    d[edge.first] = edge.second + d_v;
                    q.push({ d[edge.first], edge.first });
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        int d[101];

        for (int i = 1; i <= n; ++i) {
            d[i] = INT_MAX;
        }

        dijkstra(k, d);

        int max = 0;

        for (int i = 1; i <= n; ++i) {
            if (d[i] > max) {
                max = d[i];
            }
        }

        if (max != INT_MAX) {
            return max;
        } else {
            return -1;
        }
    }
};
