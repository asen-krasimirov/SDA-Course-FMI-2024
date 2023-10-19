#include <iostream>
#include <vector>
using namespace std;

/*
 * LeetCode contest: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 * */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] < nums[r]) {
                r = m;
            }
            else if (nums[m] > nums[r]) {
                l = m + 1;
            }
            else {
                r--;
            }
        }

        return nums[l];
    }
};

int main() {
    Solution test;

    vector<int> vec { 3, 3, 1, 3 };

    cout << test.findMin(vec);

    return 0;
}