#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l < r) {
            mid = l + (r - l) / 2;

            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            if (nums[mid] > nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return nums[0];
    }
};
