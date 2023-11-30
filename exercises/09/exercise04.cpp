#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>

using namespace std;


int main() {
    int N, cur;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i) {
        cin >> cur;

        if (cur == 0) {
            nums[i] = - 1;
        } else {
            nums[i] = 1;
        }
    }

    int sum = 0, res = 0;

    unordered_map<int,int> um;

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];

        if(sum == 0) {
            res = max(res, i + 1);
        }

        if(um.find(sum) != um.end()) {
            res = max(i - um[sum], res);
        } else {
            um[sum] = i;
        }
    }

    cout << res;

    return 0;
}
