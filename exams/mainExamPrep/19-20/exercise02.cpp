#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, Q, elem;
vector<int> arr;

bool bs(int x) {
    int l = 0, r = arr.size() - 1, m;

    while (l < r) {
        m = l + (r - l) / 2;

        if (arr[m] == x) {
            return true;
        }

        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return false;
}

int leftMost(int x) {
    int l = 0, r = arr.size() - 1, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (arr[m] == x && l == 0 && r == arr.size() - 1) {
            return m;
        }

        if (arr[m] == x) {
            return l;
        }

        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}

int rightMost(int x) {
    int l = 0, r = arr.size() - 1, m;

    while (l < r) {
        m = l + (r - l) / 2;

        if (arr[m] == x && l == 0 && r == arr.size() - 1) {
            return m;
        }

        if (arr[m] == x) {
            return r;
        }

        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}

int find_bs(int x) {
    int l = 0, r = arr.size(), m;

    while (l < r) {
        m = l + (r - l) / 2;

        if (arr[m] == x) {
            return m;
        }

        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return r;
}

int main() {
    cin >> N;

    arr = vector<int>(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cin >> Q;

    while (Q--) {
        cin >> elem;

        // cout << bs(elem) << endl;
        if (bs(elem)) {
            cout << leftMost(elem) << " " << rightMost(elem) << endl;
        } else {
            cout << find_bs(elem) << endl;
        }
    }

    return 0;
}
