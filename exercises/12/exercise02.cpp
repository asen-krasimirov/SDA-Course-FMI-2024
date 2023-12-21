#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parents = vector<int>(1001);
    vector<int> rank = vector<int>(1001, 0);

    int Find(int v) {
        if (v == parents[v]) {
            return v;
        }

        return parents[v] = Find(parents[v]);
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);

        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }

            parents[b] = a;

            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i < 1001; ++i) {
            parents[i] = i;
        }

        for (vector<int> &edge : edges) {
            int a = Find(edge[0]);
            int b = Find(edge[1]);

            if (a == b) {
                return edge;
            }

            Union(a, b);
        }

        return vector<int>();
    }
};
