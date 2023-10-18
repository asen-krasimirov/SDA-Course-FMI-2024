#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> stds(n);

    for (int i = 0; i < n; ++i) {
        cin >> stds[i];
    }

    sort(stds.begin(), stds.end());

    for (int i = 0; i < q; ++i) {
        int s, e;
        cin >> s >> e;

        auto start = lower_bound(stds.begin(), stds.end(), s);
        auto end = upper_bound(stds.begin(), stds.end(), e);

        auto result = end - start;
        if (result < 0) result = 0;

        cout << result << endl;

    }

    return 0;
}
