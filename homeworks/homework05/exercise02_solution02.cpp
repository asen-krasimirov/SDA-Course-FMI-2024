#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<long long> streets(N);
    vector<long long> leftSmallestIndexes(N);
    vector<long long> rightSmallestIndexes(N);
    stack<long long> indexes;

    for (long long i = 0; i < N; ++i) {
        cin >> streets[i];
    }

    for (long long i = 0; i < N; ++i) {
        while (!indexes.empty() && streets[indexes.top()] >= streets[i]) {
            indexes.pop();
        }

        if (indexes.empty()) {
            leftSmallestIndexes[i] = 0;
        } else {
            leftSmallestIndexes[i] = indexes.top() + 1;
        }

        indexes.push(i);
    }

    while(!indexes.empty()) {
        indexes.pop();
    }

    for (long long i = N - 1; i >= 0; --i) {
        while (!indexes.empty() && streets[indexes.top()] >= streets[i]) {
            indexes.pop();
        }

        if (indexes.empty()) {
            rightSmallestIndexes[i] = N - 1;
        } else {
            rightSmallestIndexes[i] = indexes.top() - 1;
        }

        indexes.push(i);
    }

    long long max = 0;
    for (long long i = 0; i < N; ++i) {
        long long curMax = streets[i] * (rightSmallestIndexes[i] - leftSmallestIndexes[i] + 1);
        if (curMax > max) {
            max = curMax;
        }
    }

    cout << max;

    return 0;
}
