#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <deque>

using namespace std;

int main() {
    long long N, K, curElem;
    cin >> N;

    for (long long i = 0; i < N; ++i) {
        cin >> K;

        deque<long long> stack;

        for (long long j = 0; j < K; ++j) {
            cin >> curElem;

            if (stack.size() > 0 && stack.back() == curElem * -1 && curElem < 0) {
                stack.pop_back();
            } else {
                stack.push_back(curElem);
            }
        }

        if (stack.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
