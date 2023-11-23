#include <cmath>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    class comparePoints {
    public:
        int getDistanceToCentre(vector<int> &p1) {
            return pow(p1[0], 2) + pow(p1[1], 2);
        }

        bool operator()(vector<int> &p1, vector<int> &p2) {
            return getDistanceToCentre(p1) > getDistanceToCentre(p2);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comparePoints> pq;


        /* // variant 2 (with lambda)
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        */

        for (auto point : points) {
            pq.push(point);
        }

        vector<vector<int>> res = vector<vector<int>>();

        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
