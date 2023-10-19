#include <iostream>
#include <vector>
using namespace std;

/*
 * LeetCode contest: https://leetcode.com/problems/first-bad-version/description/
 * */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n, m;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (isBadVersion(m)) r = m - 1;
            else l = m + 1;
        }

        return l;
    }
};

int main() {

    return 0;
}