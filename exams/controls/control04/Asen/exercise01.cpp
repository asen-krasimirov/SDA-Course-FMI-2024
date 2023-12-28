#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

int main() {
    int N, S, cur;
    cin >> N >> S;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; ++i) {
        cin >> cur;

        pq.push(cur);
    }

    int ctr = 0;

    while (!pq.empty() && pq.top() < S) {
        ctr++;

        int s1 = pq.top();
        pq.pop();

        if (pq.empty()) {
            break;
        }

        int s2 = pq.top();
        pq.pop();

        pq.push(s1 + 2 * s2);
    }

    if (pq.top() >= S) {
        cout << ctr;
    } else {
        cout << -1;
    }

    return 0;
}
