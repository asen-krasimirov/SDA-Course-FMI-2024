#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

# include <iomanip>
# include <queue>

using namespace std;

struct MedianFinder {
    priority_queue<double> max;
    priority_queue<double, vector<double>, greater<double>> min;

    void addElem(double elem) {
        if (max.empty() || max.top() > elem) {
            max.push(elem);
        } else {
            min.push(elem);
        }

        if (max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        } else if (min.size() > max.size() + 1) {
            max.push(min.top());
            min.pop();
        }
    }

    double findMedian() {
        if (min.size() == max.size()) {
            if (max.empty()) {
                return 0;
            }

            return (max.top() + min.top()) / 2.0;
        } else {
            return min.size() > max.size() ? min.top() : max.top();
        }
    }
};

int main() {
    cout << fixed << setprecision(1);

    int N;
    double cur;

    cin >> N;

    MedianFinder medianFinder;

    for (int i = 0; i < N; ++i) {
        cin >> cur;
        medianFinder.addElem(cur);
        cout << medianFinder.findMedian() << endl;
    }


    return 0;
}
