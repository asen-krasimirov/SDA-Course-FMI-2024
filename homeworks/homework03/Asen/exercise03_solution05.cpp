#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long devs[100001];
long long N, T;

bool checkSum(long long targetSum) {
    long long curSum = 0;
    long long teamCount = 0;

    int i = 0;
    while (i < N) {
        curSum += devs[i];

        if (devs[i] > targetSum) {
            return false;
        }

        if (curSum > targetSum) {
            teamCount++;
            curSum = 0;
            i--;
        }

        i++;
    }

    teamCount++;

    return teamCount <= T;
}

long long bs(long long biggestTeam) {
    long long l = 0, r = biggestTeam, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (checkSum(m)) r = m - 1;
        else l = m + 1;
    }

    return l;
}

int main() {
    cin >> N >> T;

    for (int i = 0; i < N; ++i) {
        cin >> devs[i];
    }

    if (N > T) {
        long long biggestTeam = 0;
        for (int i = 0; i < N; ++i) {
            biggestTeam += devs[i];
        }

        cout << bs(biggestTeam);
    }
    else {
        long long biggestElem = 0;
        for (int i = 0; i < N; ++i) {
            if (devs[i] > biggestElem) biggestElem = devs[i];
        }

        cout << biggestElem;
    }

    return 0;
}
