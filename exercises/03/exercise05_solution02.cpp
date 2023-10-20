#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int printers[100001];
long long paper, k;

bool checkTime(long long time) {
    long long curPaper = 0;
    for (int i = 0; i < k; ++i) {
        curPaper += time / printers[i];
        if (curPaper >= paper) return true;
    }
    return false;
}

long long bs(long long time) {
    long long l = 0, r = time, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (checkTime(m)) r = m - 1;
        else l = m + 1;
    }

    return l;
}

int main() {
    cin >> paper >> k;

    long long longestTime = 0;
    for (int i = 0; i < k; ++i) {
        cin >> printers[i];
        if (printers[i] > longestTime) longestTime = printers[i];
    }

    cout << bs(paper * longestTime);

    return 0;
}
