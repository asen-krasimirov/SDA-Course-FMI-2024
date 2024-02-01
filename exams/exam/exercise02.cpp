#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> arr;

// int bs(int x) {
//     int l = 0, r = N, m;

//     while (l < r) {
//         // cout << m << endl;
//         // m = l + (r - l) / 2;
//         m = (l + r) / 2;

//         if (arr[m] > x) {
//             l = m + 1;
//         } else {
//             r = m - 1;
//         }
//     }

//     return m;
// }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> N;

    arr = vector<int>(N);
    int x;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cin >> Q;

    // for (auto e : arr) {
    //     cout << e << " ";
    // }

    // cout << endl;

    reverse(arr.begin(), arr.end());

    // for (auto e : arr) {
    //     cout << e << " ";
    // }

    while (Q--) {
        cin >> x;
        auto lower_b = lower_bound(arr.begin(), arr.end(), x);
        auto upper_b = upper_bound(arr.begin(), arr.end(), x);

        // cout << "lower: " << *(lower_b + 1) << endl << "upper: " << (*upper_b + 1) << endl;

        // if (lower_b == upper_b) {
        if (lower_b != arr.end()) {
            cout << *(lower_b + 1) << endl;
        } else {
            cout << -1 << endl;
        }
        // }
        // else {
        //     if (upper_b != arr.end()) {
        //         cout << *(upper_b + 1) << endl;
        //     } else {
        //         cout << -1 << endl;
        //     }
        // }

    }

    return 0;
}
