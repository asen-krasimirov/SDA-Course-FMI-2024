#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

struct Friend {
    int arrival, leave, seatTaken;
};

class compareFriends {
public:
    bool operator()(const Friend *f1, const Friend *f2) {
        if (f1->leave == f2->leave) {
            return f1->arrival > f2->arrival;
        }

        return f1->leave > f2->leave;
    }
};

bool cmp(const pair<Friend, int> &f1, const pair<Friend, int> &f2) {
    return f1.first.arrival < f2.first.arrival;
}

int main() {
    int N, A, L, T;
    cin >> N;

    vector<pair<Friend, int>> v;

    for (int i = 0; i < N; ++i) {
        cin >> A >> L;
        v.push_back({{A, L}, i});
    }

    sort(v.begin(), v.end(), cmp);

    cin >> T;

    priority_queue<Friend*, vector<Friend*>, compareFriends> pq;
    priority_queue<int, vector<int>, greater<int>> freeSeats;

    for (int i = 0; i < N; ++i) {
        freeSeats.push(i);
    }

    for (int i = 0; i < N; ++i) {
        pair<Friend, int> &f = v[i];

        pq.push(&f.first);

        while (!pq.empty() && pq.top()->leave <= f.first.arrival) {
            freeSeats.push(pq.top()->seatTaken);
            pq.pop();
        }

        int freeSeatIdx = freeSeats.top();
        freeSeats.pop();
        f.first.seatTaken = freeSeatIdx;

        if (f.second == T) {
            cout << freeSeatIdx;
            break;
        }

    }

    return 0;
}
