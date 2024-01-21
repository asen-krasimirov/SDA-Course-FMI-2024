#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Q, x;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cin >> Q;

    while (Q--) {
        cin >> x;

        auto lower_b = lower_bound(arr.begin(), arr.end(), x);

        if (*lower_b != x) {
            cout << lower_b - arr.begin() << endl;
        } else {
            auto upper_b = upper_bound(arr.begin(), arr.end(), x);

            cout << lower_b - arr.begin() << " ";
            cout << upper_b - arr.begin() - 1 << endl;
        }
    }

    return 0;
}
