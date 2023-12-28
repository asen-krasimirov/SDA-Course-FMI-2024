#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <set>
#include <climits>

using namespace std;

long long findMinXor(long long a, long long b, long long c) {
    return min(a ^ b, b ^ c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Q, curNum, minXor = INT_MAX;
    cin >> Q;

    if (Q == 0) {
        return 0;
    }

    set<long long> nums;
    nums.insert(0);

    cin >> curNum;
    nums.insert(curNum);

    cout << curNum << endl;

    for (long long i = 1; i < Q; ++i) {
        cin >> curNum;

        nums.insert(curNum);

        auto curElem = nums.find(curNum);

        auto nextElem = curElem;
        ++nextElem;

        auto prevElem = curElem;
        --prevElem;

        if (nextElem == nums.end()) {
            --prevElem;
            --nextElem;
            --curElem;
        }

        minXor = min(minXor, findMinXor(*prevElem, *curElem, *nextElem));

        cout << minXor << endl;
    }

    return 0;
}
