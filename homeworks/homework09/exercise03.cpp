#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>
#include <climits>

using namespace std;


int main() {
    int N, n, res, smallest = INT_MAX;
    cin >> N;

    unordered_map<int, int> um;

    for (int i = 0; i < N; ++i) {
        cin >> n;

        if (um.find(n) == um.end()) {
            um[n] = i;
        } else {
            res = i - um[n];
            if (res < smallest) {
                smallest = res;
            }
        }
    }

    cout << smallest;

    return 0;
}
