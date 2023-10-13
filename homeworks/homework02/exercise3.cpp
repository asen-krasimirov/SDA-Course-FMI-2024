#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<pair<double, int>, int>> boys;

    for (int i = 1; i <= N; ++i) {
        double di, ti;
        cin >> di >> ti;
        boys.push_back(pair<pair<double, int>, int>(pair<double, int>((di * di) / ti, di), i));
    }

    sort(boys.begin(), boys.end());

    for (int i = N - 1; i >= 0; --i) {
        cout << boys[i].second;
        if (i != 0) cout  << " ";
    }

    return 0;
}
