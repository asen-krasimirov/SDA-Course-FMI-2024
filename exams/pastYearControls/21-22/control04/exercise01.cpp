#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>
#include <climits>

using namespace std;

struct Query {
    int start, wait;

    bool operator>(const Query &other) const {
        return wait > other.wait;
    }
};

priority_queue<Query, vector<Query>, greater<Query>> pq;
vector<int> times;

int MIN = INT_MAX;
int MAX = INT_MIN;

int main() {
    int N, totalStart = 0;
    cin >> N;

    times = vector<int>(N);

    for (int i = 0; i < N; ++i) {
        cin >> times[i];
    }

    pq.push({ 0, times[0] });

    for (int i = 0; i < N; ++i) {
        int neededTime = totalStart + pq.top().wait - pq.top().start;

        MIN = min(MIN, neededTime);
        MAX = max(MAX, neededTime);

        int finishTime = totalStart + pq.top().wait;
        pq.pop();

        for (int j = totalStart + 1; j <= finishTime && j < N; ++j) {
            pq.push({ j, times[j] });
        }

        totalStart = finishTime;
    }


    cout << MIN << " " << MAX;

    return 0;
}
