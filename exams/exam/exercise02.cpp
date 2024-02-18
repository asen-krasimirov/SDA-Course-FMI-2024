#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> arr;

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
    reverse(arr.begin(), arr.end());

    while (Q--) {
        cin >> x;
        auto lower_b = lower_bound(arr.begin(), arr.end(), x);
        auto upper_b = upper_bound(arr.begin(), arr.end(), x);

        if (lower_b != arr.end()) {
            cout << *(lower_b + 1) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
