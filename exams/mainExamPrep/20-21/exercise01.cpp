#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr1(N);
    vector<int> arr2(M);

    for (int i = 0; i < N; ++i) {
        cin >> arr1[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < M; ++i) {
        int cur = arr2[i];

        auto lower_b = lower_bound(arr1.begin(), arr1.end(), cur);

        cout << lower_b - arr1.begin() << " ";
    }

    return 0;
}
