#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

int tX, tY, N, K;

class comparePoints {
public:
    static double getDistanceToTourist(pair<int, int> &p1) {
        return pow(tX - p1.first, 2) + pow(tY - p1.second, 2);
    }

    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        double distance1 = getDistanceToTourist(p1);
        double distance2 = getDistanceToTourist(p2);

        return distance1 > distance2 || (distance1 == distance2 && p1.first > p2.first) ||
               (distance1 == distance2 && p1.first == p2.first && p1.second > p2.second);
    }
};

int main() {
    cin >> tX >> tY >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, comparePoints> pq;

    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        pq.emplace(x, y);
    }

    for (int i = 0; i < K; ++i) {
        cout << pq.top().first << " " << pq.top().second;
        pq.pop();
        cout << endl;
    }

    return 0;
}
