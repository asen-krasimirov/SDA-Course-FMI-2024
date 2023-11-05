#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

/* see solution02 for 100/100 */

int main() {
    size_t N;
    cin >> N;

    vector<size_t> streets(N);

    for (size_t i = 0; i < N; ++i) {
        cin >> streets[i];
    }

    queue<size_t> checkedStreets;

    size_t result = 0;

    for (long long i = N - 1; i >= 0; --i) {
        if (checkedStreets.empty()) {
            checkedStreets.push(streets[i]);
            continue;
        }

        if (checkedStreets.front() > streets[i]) {
            checkedStreets.push(streets[i]);
        }
        else if (checkedStreets.front() < streets[i]) {
            checkedStreets.push(streets[i]);
            result = streets[i] * checkedStreets.size();

            while (!checkedStreets.empty()) {
                checkedStreets.pop();
            }

            checkedStreets.push(streets[i]);
        }
        else if (streets[i] == checkedStreets.front()) {
            checkedStreets.push(streets[i]);
            result = streets[i] * checkedStreets.size();
        }
    }

    cout << result;

    return 0;
}
