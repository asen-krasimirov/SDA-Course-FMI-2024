#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<pair<double, double>, int>> teamStats;

    for (int i = 1; i <= N; ++i) {
        double teammates, enemies;
        cin >> teammates >> enemies;

        double score = teammates * teammates / enemies;

        teamStats.push_back(pair<pair<double, double>, int>(pair<double, double>(score, teammates), i));
    }

    sort(teamStats.begin(), teamStats.end(), greater());

    for (auto team: teamStats) {
        cout << team.second << " ";
    }

    return 0;
}
