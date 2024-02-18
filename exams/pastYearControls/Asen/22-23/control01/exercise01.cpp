#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<pair<int, int>> arr;
vector<pair<int, int>> cpy;

int bs(pair<int, int> a) {
    int l = 0, r = arr.size(), m;

    while (l <= r) {
        m = (l + r) / 2;

        if (arr[m].first == a.first) {
            if (arr[m].second == a.second) {
                return m;
            }

            if (arr[m].second > a.second) {
                r = m - 1;
            } else {
                l = m + 1;
            }

            continue;
        }

        if (arr[m].first > a.first) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return m;
}

int main() {
    int N, x;
    cin >> N;


    for (int i = 0; i < N; ++i) {
        cin >> x;
        arr.push_back({x, i});
        cpy.push_back({x, i});
    }

    sort(arr.begin(), arr.end());

    for (auto e : cpy) {
        int idx = bs(e);

        cout << idx << " ";
    }

    return 0;
}
