#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double epsilon = 0.000000001;

struct Bodybuilder {
    double di;
    double ti;
    double eff;
    int place;
    bool operator<(Bodybuilder& other) const{
        if (abs(eff - other.eff) < epsilon) {
            return di < other.di;
        }
        return eff < other.eff;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Bodybuilder> bodybuilders(n);
    for (int i = 0; i < n; i++) {
         double di,ti;
        cin >> di >>ti;
        bodybuilders[i].di=di;
        bodybuilders[i].ti=ti;
        double r = di / 2;
        bodybuilders[i].eff = di * di / ti;
        bodybuilders[i].place = i + 1;
    }
    sort(bodybuilders.begin(), bodybuilders.end());
    for (int i = n-1; i >=0; i--) {
        cout << bodybuilders[i].place << ' ';
    }
    return 0;
}
