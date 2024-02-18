#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

int K, T, B, N;
deque<int> queries;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    cin >> K >> T >> B;
    cin >> N;

    queries = deque<int>();

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        queries.push_back(x);
    }

    int groupCtr = 0;

    while (groupCtr++ < B) {
        if (N > 0) {
            for (int i = 0; i < T && !queries.empty(); ++i) {
                pq.push(queries.front());
                queries.pop_front();
            }
        }

        for (int i = 0; i < K && !pq.empty(); ++i) {
            cout << pq.top() << " ";
            pq.pop();
        }

        N -= T;
    }

    return 0;
}
