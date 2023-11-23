#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <deque>
#include <set>

using namespace std;


int main() {
    int N, M, curNum, i;
    cin >> N >> M;

    deque<int> nums;
    set<int> uniqueNums;

    for (i = 0; i < M; ++i) {
        cin >> curNum;
        nums.push_back(curNum);
        uniqueNums.insert(curNum);
    }

    i = 1;
    while (!nums.empty()) {
        if (uniqueNums.find(i) != uniqueNums.end()) {
            i++;
            continue;
        }

        if (i < nums.front()) {
            cout << i++ << " ";
        } else if (i >= nums.front()) {
            cout << nums.front() << " ";
            uniqueNums.erase(nums.front());
            nums.pop_front();
        }
    }

    for (; i <= N; ++i) {
        cout << i << " ";
    }

    return 0;
}
