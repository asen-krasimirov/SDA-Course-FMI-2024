#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ctr;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums.size(); ++i) {
            ctr[nums[i]]++;
        }

        for (auto elem : ctr) {
            pq.push({ elem.second, elem.first });
        }


        vector<int> res;

        while (k--) {
            pair<int, int> top = pq.top();
            res.push_back(top.second);
            pq.pop();
        }

        return res;
    }
};
