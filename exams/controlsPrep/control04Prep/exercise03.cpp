#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <climits>

using namespace std;

/* not valid solution (I don't understand the problem) */

int main() {
    int N, A;
    cin >> N;

    int sWait = INT_MAX;

    int lWait = 0;

    for (int i = 1; i < N; ++i) {
        cin >> A;
        A += i;

        if (A < sWait) {
            sWait = A;
        } else if (A > lWait) {
            lWait = A;
        }
    }

    cout << sWait << " " << lWait;

    return 0;
}
