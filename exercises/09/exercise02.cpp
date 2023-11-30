#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> all;
        unordered_set<int> uniques;

        for (int i = 0; i < nums.size(); ++i) {
            if (all.count(nums[i] - k) != 0) {
                uniques.insert(nums[i] - k);
            }

            if (all.count(nums[i] + k) != 0) {
                uniques.insert(nums[i]);
            }

            all.insert(nums[i]);
        }

        return uniques.size();
    }
};
