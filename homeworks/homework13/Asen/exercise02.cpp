#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

const int MAX_N = 100001;
const int MAX_NUM = 200001;
const int INF = 100000001;

int a[MAX_N], n, q;
int atPos[MAX_NUM];
std::vector<int> divs[MAX_NUM], v[MAX_NUM];

int binary(int value, int to) {
    int l = -1, r = v[value].size(), mid;

    while (l < r - 1) {
        mid = (l + r) / 2;

        if (v[value][mid] <= to) {
            l = mid;
        } else {
            r = mid;
        };
    }

    return r;
}

int main() {
    std::cin >> n >> q;

    for (int i = 1 ; i <= n ; ++i) {
        std::cin >> a[i];
    }

    for (int i = 1 ; i <= MAX_NUM - 1 ; ++i) {
        for (int j = 2 * i ; j <= MAX_NUM - 1 ; j += i) {
            divs[j].push_back(i);
        }
    }

    for (int i = 1 ; i <= n ; ++i) {
        for (int j = a[i] ; j <= MAX_NUM - 1 ; j += a[i]) {
            v[j].push_back(i);
        }

        for (int j : divs[a[i]]) {
            v[j].push_back(i);
        }
    }

    int l, r, d;

    for (int i = 1 ; i <= q ; ++i) {
        std::cin >> l >> r >> d;
        std::cout << binary(d, r) - binary(d, l-1) << ' ';
    }

    return 0;
}
