#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> window;

        for (int i =  0; i < nums.size(); ++i) {
            auto first_bigger = window.lower_bound(nums[i] - valueDiff);

            if (first_bigger != window.end() && *first_bigger <= nums[i] + valueDiff) {
                return true;
            }

            window.insert(nums[i]);

            if (window.size() > indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};
