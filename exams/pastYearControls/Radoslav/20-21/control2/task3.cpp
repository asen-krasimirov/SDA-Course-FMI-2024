#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double epsilon = 0.000000001;

struct Pair {
    double x, y;
    int index;
    double eff = (x * x) / y;
    Pair(double x, double y, int index) :x(x), y(y), index(index) {}
    bool operator<(const Pair& other)const {
        if (abs(eff - other.eff) < epsilon) {
            return x < other.x;
        }
        return eff < other.eff;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Pair> arr;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back(Pair(x, y, i + 1));
    }
    sort(arr.begin(), arr.end());
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i].index << " ";
    }
    return 0;
}