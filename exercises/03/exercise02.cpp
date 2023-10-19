#include <iostream>
#include <vector>
using namespace std;

/*
 * LeetCode contest: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
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
            else {
                l = m + 1;
            }
        }

        return nums[l];
    }
};

int main() {
    Solution test;

//    vector<int> vec { 2, 1 };
    vector<int> vec {3,4,5,1,2};

    cout << test.findMin(vec);

    return 0;
}