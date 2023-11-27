#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

class timesComparator {
public:
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }

        return p1.second > p2.second;
    }
};

bool comparator(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first < p2.first;
}

int main() {
    int N, X, Y, maxC = 0;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; ++i) {
        cin >> X >> Y;
        v.push_back({X, Y});
    }

    sort(v.begin(), v.end(), comparator);

    priority_queue<pair<int, int>, vector<pair<int, int>>, timesComparator> pq;

    for (int i = 0; i < N; ++i) {
        pair<int, int> f = v[i];

        if (f.first == f.second) {
            continue;
        }

        pq.push(f);

        while (!pq.empty() && pq.top().second <= f.first) {
            pq.pop();
        }

        if (maxC < pq.size()) {
            maxC = pq.size();
        }
    }

    cout << maxC;

    return 0;
}
