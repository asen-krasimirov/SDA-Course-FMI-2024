#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <stack>

using namespace std;

int N, K;

int main() {
    cin >> N;

    while (N--) {
        cin >> K;

        stack<int> s;

        for (int i = 0; i < K; ++i) {
            int x;
            cin >> x;

            if (!s.empty() && s.top() * -1 == x && s.top() >= 0) {
                s.pop();
            } else {
                s.push(x);
            }
        }

        if (s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
