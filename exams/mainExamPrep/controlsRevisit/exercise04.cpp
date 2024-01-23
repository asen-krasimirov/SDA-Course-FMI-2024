#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

# include <iomanip>
#include <queue>

using namespace std;

long long N, x;
priority_queue<double> pMax;
priority_queue<double, vector<double>, greater<>> pMin;

int main() {
    cout << fixed << setprecision(1);

    cin >> N;

    while (N--) {
        cin >> x;

        if (pMax.empty() || pMax.top() > x) {
            pMax.push(x);
        } else {
            pMin.push(x);
        }

        if (pMin.size() > pMax.size() + 1) {
            pMax.push(pMin.top());
            pMin.pop();
        } else if (pMax.size() > pMin.size() + 1) {
            pMin.push(pMax.top());
            pMax.pop();
        }

        if (pMax.size() == pMin.size()) {
            double res = pMax.top() + pMin.top();
            cout << res / 2.0 << endl;
        } else {
            double res = pMin.size() > pMax.size() ? pMin.top() : pMax.top();
            cout << res << endl;
        }
    }

    return 0;
}
