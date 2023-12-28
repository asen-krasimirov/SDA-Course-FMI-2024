#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkTeamSum(vector<long long> &devs, long long targetSum, int T) {
    long long curSum = 0;
    int teamCount = 0;

    for (int i = 0; i < devs.size(); ++i) {
        curSum += devs[i];

        if (devs[i] > targetSum) {
            return false;
        }

        if (curSum > targetSum) {
            teamCount++;
            curSum = 0;
            i--;
        }
    }

    teamCount++;

    return teamCount <= T;
}

long long binarySearch(vector<long long> &devs, long long biggestTeam, int T) {
    long long l = 0, r = biggestTeam, m;
    long long minMaxTeamSum = 0;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (checkTeamSum(devs, m, T)) {
            minMaxTeamSum = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    return minMaxTeamSum;
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<long long> devs(N);

    sort(devs.begin(), devs.end());

    if (N > T) {
        long long biggestTeam = 0;
        for (int i = 0; i < N; ++i) {
            int dev;
            cin >> dev;
            devs[i] = dev;
            biggestTeam += dev;
        }

        cout << binarySearch(devs, biggestTeam, T);
    }
    else {
        cout << devs[T - 1];
    }

    return 0;
}
