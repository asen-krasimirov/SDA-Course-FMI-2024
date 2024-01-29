#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

struct Friend {
    int a, l, takenSeat;
};

struct compareFriends {
    bool operator()(const pair<Friend, int> &first, const pair<Friend, int> &second) {
        if (first.first.a == second.first.a) {
            return first.first.l < second.first.l;
        }
        return first.first.a > second.first.a;
    }
};

int main() {
    int N, a, l, T;
    cin >> N;

    // queue<pair<int, int>> q;
    priority_queue<pair<Friend, int>, vector<pair<Friend, int>>, compareFriends> pq;

    for (int i = 0; i < N; ++i) {
        cin >> a >> l;
        pq.push({{ a, l, -1 }, i});
    }

    cin >> T;

    priority_queue<int, vector<int>, greater<int>> seats;

    for (int i = 0; i < N; ++i) {
        seats.push(i);
    }

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        while (!pq.empty() && top.first.a > pq.top().first.l) {
            seats.push(pq.top().first.takenSeat);
            pq.pop();
        }

        int freeSeat = seats.top();
        seats.pop();
        top.first.takenSeat = freeSeat;

        if (top.second == T) {
            cout << freeSeat;
            break;
        }
    }

    return 0;
}