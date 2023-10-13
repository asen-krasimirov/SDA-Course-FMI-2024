#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned N, K;
    vector<unsigned> results;

    cin >> N >> K;

    unsigned curRes = 0;
    for (unsigned i = 0; i < N; ++i) {
        cin >> curRes;
        results.push_back(curRes);
    }

    sort(results.begin(), results.end());

    unsigned smallestDiff = 10e9 + 1;

    for (unsigned i = 0; i + K <= N; ++i) {
        unsigned curDiff = results[i + K - 1] - results[i];
        if (curDiff < smallestDiff) smallestDiff = curDiff;
    }

    cout << smallestDiff;

    return 0;
}