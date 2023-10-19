#include <iostream>
#include <vector>
using namespace std;

/*
 * LeetCode contest: https://leetcode.com/problems/plus-one/description/
 * */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i != -1; --i) {
            if (digits[i] == 9 && i == 0) {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
            }
            else if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                break;
            }
        }

        return digits;
    }
};

int main() {

    return 0;
}
