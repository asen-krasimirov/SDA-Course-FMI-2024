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

    stack<pair<size_t, size_t>> daysCounter;

    for (size_t i = 0; i < N; i++) {
        curMaxDays = 0;
        curPlayer = players[i];

        while (!daysCounter.empty() && daysCounter.top().first >= curPlayer) {
            curMaxDays = max(curMaxDays, daysCounter.top().second);
            daysCounter.pop();
        }

        if (!daysCounter.empty()) {
            daysCounter.top().second = max(curMaxDays, daysCounter.top().second) + 1;
            maxDays = max(maxDays, daysCounter.top().second);
        }

        daysCounter.push({ curPlayer, 0 });
    }

    cout << maxDays;

    return 0;
}
