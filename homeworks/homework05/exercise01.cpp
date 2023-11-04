#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    deque<long long> positives;
    long long topElem;

    long long cur;

    for (long long i = 0; i < N; ++i) {
        cin >> cur;

        if (cur >= 0) {
            positives.push_back(cur);
            continue;
        }

        if (positives.empty()) {
            cout << cur << " ";
            continue;
        }

        cur *= -1;

        while (!positives.empty()) {
            topElem = positives.back();

            if (cur < topElem) {
                cur *= -1;
                break;
            }
            if (cur > topElem) {
                positives.pop_back();
            }
            else if (cur == topElem) {
                positives.pop_back();
                cur *= -1;
                break;
            }
        }

        if (cur < 0) {
            continue;
        }

        cout << cur * -1 << " ";
    }

    while (!positives.empty()) {
        cout << positives.front() << " ";
        positives.pop_front();
    }

    cout << endl;

    return 0;
}