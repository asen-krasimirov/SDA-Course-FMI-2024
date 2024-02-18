#include <bits/stdc++.h>
using namespace std;

int N, Q, x;
vector<int> arr;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> N;

    arr = vector<int>(N);

    for (int i = N - 1; i >= 0; --i) {
        cin >> arr[i];
    }

    cin >> Q;

    while (Q--) {
        cin >> x;

        auto upper_b = lower_bound(arr.begin(), arr.end(), x);

        int idx = upper_b - arr.begin();

        if (idx >= arr.size()) {
            cout << -1;
        } else {
            if (idx == arr.size()) {
                idx--;
            }
            cout << arr[idx + 1];
        }

        cout << endl;
    }

    return 0;
}
