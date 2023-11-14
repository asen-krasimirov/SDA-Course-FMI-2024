/* HackerRank: https://www.hackerrank.com/contests/sda-hw-5/challenges/challenge-2695 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <deque>

using namespace std;


int main() {
    long long N, d;
    cin >> N >> d;
    deque<pair<long long, long long>> mins;

    long long elem, elemMin;

    long long minsSum = 0;

    for (long long i = 0; i < N; ++i) {
        cin >> elem;

        if (mins.size() == d) {
            minsSum += mins.back().second;
            mins.pop_front();
        }

        if (mins.size() == 0) {
            mins.push_back({elem, elem});
        } else {
            elemMin = mins.back().second < elem ? mins.back().second : elem;
            mins.push_back({elem, elemMin});
        }
    }

    cout << minsSum;

    return 0;
}
