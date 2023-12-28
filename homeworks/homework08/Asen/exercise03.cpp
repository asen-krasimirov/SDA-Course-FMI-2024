#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

int Q, N, C, K, X, Y, curC;

struct Query {
    int c, beg, end;
};

class compareQueries {
public:
    bool operator()(const Query &q1, const Query &q2) {
        if (q1.end == q2.end) {
            return q1.beg > q2.beg;
        }

        return q1.end > q2.end;
    }
};

bool cmp(Query &q1, Query &q2) {
    return q1.beg < q2.beg;
}

int main() {
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        cin >> N >> C;

        vector<Query> v;

        for (int j = 0; j < N; ++j) {
            cin >> K >> X >> Y;
            v.push_back({K, X, Y});
        }

        sort(v.begin(), v.end(), cmp);

        priority_queue<Query, vector<Query>, compareQueries> pq;

        for (int j = 0; j < N; ++j) {
            Query q = v[j];

            if (q.beg == q.end) {
                continue;
            }

            pq.push(q);
            curC += q.c;

            while (!pq.empty() && pq.top().end <= q.beg) {
                curC -= pq.top().c;
                pq.pop();
            }

            if (curC > C) {
                break;
            }
        }

        if (curC <= C) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }

        curC = 0;

    }

    return 0;
}
