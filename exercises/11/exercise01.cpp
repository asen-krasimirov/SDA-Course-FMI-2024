#include <vector>
#include <climits>

using namespace std;

/* Bellman- Ford algorithm solution */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unsigned d[101];

        for (int i = 0; i < 101; ++i) {
            d[i] = -1;
        }

        d[k] = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (vector<int> edge : times) {
                if (d[edge[0]] < INT_MAX) {
                    d[edge[1]] = min(d[edge[1]], d[edge[0]] + edge[2]);
                }
            }
        }

        unsigned max = 0;

        for (int i = 1; i <= n; ++i) {
            if (d[i] > max) {
                max = d[i];
            }
        }

        if (max == INT_MAX) {
            return - 1;
        } else {
            return max;
        }
    }
};
