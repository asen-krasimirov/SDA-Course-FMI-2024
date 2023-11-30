#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> all;

        for (int i = 0; i < nums.size(); ++i) {
            all.insert(nums[i]);
        }

        int maxS = 0, cur = 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (all.find(nums[i] -  1) != all.end()) {
                continue;
            }

            int numToFind = nums[i] + 1;

            while (all.find(numToFind) != all.end()) {
                cur++;
                numToFind++;
            }

            if (maxS < cur) {
                maxS = cur;
            }

            cur = 1;
        }

        return maxS;
    }
};
