#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;


int main() {
    int N, val;
    cin >> N;

    priority_queue<int> pq;

    for (int i = 0; i < N; ++i) {
        cin >> val;

        if (val == -1) {
            if (!pq.empty()) {
                cout << pq.top() << " ";
                pq.pop();
            }
        } else {
            pq.push(val);
        }
    }

    return 0;
}
