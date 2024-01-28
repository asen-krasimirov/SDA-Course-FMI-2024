#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>

using namespace std;

unordered_map<int, int> starts;

int main() {
    int N, x, best = 0, startIdx = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x;

        if (starts.find(x) == starts.end() || starts[x] < startIdx) {
            starts[x] = i;
        } else {
            best = max(best, i - startIdx);

            startIdx = starts[x] + 1;
            starts[x] = i;
        }
    }

    best = max(best, N - startIdx);

    cout << best;

    return 0;
}
