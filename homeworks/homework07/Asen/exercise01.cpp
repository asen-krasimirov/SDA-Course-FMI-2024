#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <map>

using namespace std;

int main() {
    int N, B, bIdx;
    cin >> N >> B;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];

        if (nums[i] == B) {
            bIdx = i;
        }
    }

    map<int, int> leftBalance, rightBalance;
    int balance = 0;

    for (int i = bIdx - 1; i >= 0; --i) {
        if (nums[i] < B) {
            balance--;
        } else {
            balance++;
        }

        leftBalance[balance]++;
    }

    balance = 0;

    for (int i = bIdx + 1; i < N; ++i) {
        if (nums[i] < B) {
            balance--;
        } else {
            balance++;
        }

        rightBalance[balance]++;
    }

    int ctr = 1;

    for (auto lBalance : leftBalance) {
        auto rBalance = rightBalance.find(lBalance.first * -1);

        if (rBalance != rightBalance.end()) {
            ctr += lBalance.second * rBalance->second;
        }
    }

    if (leftBalance.count(0) != 0) {
        ctr += leftBalance[0];
    }

    if (rightBalance.count(0) != 0) {
        ctr += rightBalance[0];
    }

    cout << ctr;

    return 0;
}
