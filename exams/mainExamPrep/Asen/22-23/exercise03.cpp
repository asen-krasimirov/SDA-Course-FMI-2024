#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

/* 13.33 for some reason */

struct Friend {
    int a, l, i, takenSeat;
};

struct compareFriends {
    bool operator()(const Friend &first, const Friend &second) {
        if (first.l == second.l) {
            return first.a > second.a;
        }
        return first.l > second.l;
    }
};

bool cmp(const Friend &first, const Friend &second) {
    return first.a < second.a;
}

int main() {
    int N, a, l, T;
    cin >> N;

    // priority_queue<Friend, vector<Friend>, compareFriends> friends;
    vector<Friend> friends;
    priority_queue<int, vector<int>, greater<>> seats;

    for (int i = 0; i < N; ++i) {
        cin >> a >> l;
        friends.push_back({ a, l, i });
        seats.push(i);
    }

    sort(friends.begin(), friends.end(), cmp);

    priority_queue<Friend, vector<Friend>, compareFriends> pq;

    cin >> T;

    // while (!friends.empty()) {
    for (int i = 0; i < N; ++i) {
        Friend top = friends[i];

        pq.push(top);

        while (!pq.empty() && top.a >= pq.top().l) {
            seats.push(pq.top().takenSeat);
            pq.pop();
        }

        int freeSeat = seats.top();
        seats.pop();

        if (top.i == T) {
            cout << freeSeat;
            break;
        } else {
            top.takenSeat = freeSeat;
        }
    }

    return 0;
}
