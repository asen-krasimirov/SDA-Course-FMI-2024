#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int main() {
    size_t N, curPlayer, curMaxDays, maxDays = 0;
    cin >> N;

    vector<size_t> players(N);

    for (size_t i = 0; i < N; i++) {
        cin >> players[i];
    }

    stack<pair<size_t, size_t>> bestDays;

    for (size_t i = 0; i < N; i++) {
        curMaxDays = 0;
        curPlayer = players[i];

        while (!bestDays.empty() && bestDays.top().first >= curPlayer) {
            curMaxDays = max(curMaxDays, bestDays.top().second);
            bestDays.pop();
        }

        if (!bestDays.empty()) {
            bestDays.top().second = max(curMaxDays, bestDays.top().second) + 1;
            maxDays = max(maxDays, bestDays.top().second);
        }

        bestDays.push({ curPlayer, 0 });
    }

    cout << maxDays;

    return 0;
}
