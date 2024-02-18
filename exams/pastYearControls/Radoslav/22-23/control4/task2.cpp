#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        pq.push(value);
    }
    bool flag = false;
    while (!pq.empty()) {
        int w1 = pq.top();
        pq.pop();
        if (w1 >= m) {
            flag = true;
            cout << count; break;

        }
        else if (!pq.empty()) {
            count++;
            int w2 = pq.top();
            pq.pop();
            int newValue = w1 + 2 * w2;
            pq.push(newValue);
        }
    }
    if (flag == false) {
        cout << -1;
    }
    return 0;
}