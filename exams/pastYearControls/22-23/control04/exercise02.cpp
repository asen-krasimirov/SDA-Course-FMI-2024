#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;


int main() {
    int P, x, M;

    cin >> P >> M;

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < P; ++i) {
        cin >> x;
        pq.push(x);
    }

    int rounds = 0;

    while (!pq.empty()) {
        int w1 = pq.top();
        pq.pop();

        if (w1 >= M) {
            break;
        }

        if (pq.empty()) {
            rounds = -1;
            break;
        }

        int w2 = pq.top();
        pq.pop();

        pq.push(w1 + 2 * w2);
        rounds++;
    }

    cout << rounds;

    return 0;
}
