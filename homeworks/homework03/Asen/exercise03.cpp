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

    vector<pair<int, vector<int>>> teams(T);

    int teamLen = N / T;
    int teamIdx = 0;
    int localCtr = 0;
    for (int i = 0; i < N;) {
        localCtr = 0;
        int teamScore = 0;
        while(localCtr++ < teamLen) {
            teamScore += devs[i];
            teams[teamIdx].second.push_back(devs[i++]);
        }
        if (teams[teamIdx].first <= 0) teams[teamIdx].first = 0;
        teams[teamIdx].first += teamScore;
        if (teamIdx < T - 1) teamIdx++;
    }

    sort(teams.begin(), teams.end());

    /*
    for (auto team: teams) {
        for (int i : team.second) cout << i << " ";
        cout << endl << team.first << endl;
    }
    */

    while (true) {
        auto smallestSet = min_element(teams.begin(), teams.end());
        auto biggestSet = max_element(teams.begin(), teams.end());

        if (biggestSet->second.size() == 1) break;
        auto elem = *min_element(biggestSet->second.begin(), biggestSet->second.end());
        smallestSet->second.push_back(elem);
        smallestSet->first += elem;
        biggestSet->second.erase(remove(biggestSet->second.begin(), biggestSet->second.end(), elem), biggestSet->second.end());
        biggestSet->first -= elem;
    }

    cout << max_element(teams.begin(), teams.end())->first;

    return 0;
}
