#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, T;
    cin >> N >> T;

    vector<int> devs(N);

    for (int i = 0; i < N; ++i) {
        cin >> devs[i];
    }

    sort(devs.begin(), devs.end());

    vector<pair<pair<int, int>, int>> teams;    // start, end, sum

    int teamSize = N / T;
    for (int i = 0; i < T; ++i) {
//        teams[i].first = pair<int, int>(i, i + teamSize - 1);
//        teams.push_back(pair<pair<int, int>, int>(pair<int, int>(i, i + teamSize - 1), 0));
//        int j = i;
//        while (j++ < teamSize) {
//            teams[i].second += devs[j];
//        }
    }

    for (auto team: teams) {
        cout << team.second << endl;
    }

    return 0;
}
