#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;


int main() {
    int N, M;
    size_t P;
    cin >> N >> M;

    priority_queue<size_t, vector<size_t>, greater<size_t>> pq;

    for (int i = 0; i < N; ++i) {
        cin >> P;
        pq.push(P);
    }

    size_t rounds = 0;

    while (!pq.empty() && pq.top() < M) {
        size_t w1 = pq.top();
        pq.pop();

        if (pq.empty()) {
            break;
        }

        size_t w2 = pq.top();
        pq.pop();

        pq.push(w1 + 2 * w2);
        rounds++;
    }

    if (pq.empty()) {
        cout << -1;
    } else {
        cout << rounds;
    }

    return 0;
}
