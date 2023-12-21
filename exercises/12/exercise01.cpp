#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    const int INF = 1000000000;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int totalW = 0;

        int n = points.size();

        int adj[1000][1000];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i][j] = dist;
                adj[j][i] = dist;
            }
        }

        vector<bool> visited(n, false);
        vector<int> min_e(n, INF);

        min_e[0] = 0;

        for (int i = 0; i < n; ++i) {
            int v = -1;

            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (v == -1 || min_e[j] < min_e[v])) {
                    v = j;
                }
            }

            if (min_e[v] == INF) {
                exit(0);
            }

            totalW += min_e[v];
            visited[v] = true;

            for (int j = 0; j < n; ++j) {
                if (adj[v][j] < min_e[j]) {
                    min_e[j] = adj[v][j];
                }
            }
        }

        return totalW;

    }
};
