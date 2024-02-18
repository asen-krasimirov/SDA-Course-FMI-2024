#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

struct timeComparator {
    bool operator()(const pair<int, int> &first, const pair<int, int> &second) {
        if (first.second == second.second) {
            return first.first > second.first;
        }
        return first.second > second.second;
    }
};

int main() {
    int N, s, e;
    cin >> N;

    vector<pair<int, int>> times;
    priority_queue<pair<int, int>, vector<pair<int, int>>, timeComparator> pq;

    for (int i = 0; i < N; ++i) {
        cin >> s >> e;
        times.push_back({ s, e });
    }

    int MAX = 0;

    sort(times.begin(), times.end());

    for (int i = 0; i < N; ++i) {
        pair<int, int> cur = times[i];

        if (cur.first == cur.second) {
            continue;
        }

        pq.push(cur);

        while (!pq.empty() && pq.top().second <= cur.first) {
            pq.pop();
        }

        MAX = max(MAX, (int) pq.size());
    }

    cout << MAX;

    return 0;
}
