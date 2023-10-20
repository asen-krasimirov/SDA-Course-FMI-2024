#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Not 100/100, view Koceto's Solution for 100/100 solution (or solution02)
 * Hackerrank: https://www.hackerrank.com/contests/sda-homework-3/challenges/challenge-2674/problem
 * */

bool checkTime(int papers, vector<int> &printers, int time) {
    int couldPrint = 0;
    for (int printer: printers) {
        couldPrint += time / printer;
        if (couldPrint >= papers) return true;
    }
    return false;
}

int findSmallestTime(int papers, vector<int> &printers, int time) {
    int l = 0, r = time, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (checkTime(papers, printers, m)) r = m - 1;
        else l = m + 1;
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> times;

//    unsigned maxTime = 0;
    for (int i = 0; i < k; ++i) {
        int curTime;
        cin >> curTime;
//        maxTime += curTime;
        times.push_back(curTime);
    }

    sort(times.begin(), times.end());

//    maxTime *= (n / k) + 1;
    long long maxTime = n * times[k - 1];

    cout << findSmallestTime(n, times, maxTime);

    return 0;
}
