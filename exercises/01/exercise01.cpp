#include <iostream>
#include <vector>
using namespace std;

/*
 * LeetCode contest: https://leetcode.com/problems/move-zeroes/description/
 * */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ctr = 0;
        int idx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ctr++;
            }
            else {
                nums[idx++] = nums[i];
            }
        }

        for (int i = idx; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

int main() {

    return 0;
}
