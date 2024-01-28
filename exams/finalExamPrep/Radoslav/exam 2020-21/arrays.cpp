#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


typedef long long ll;

struct Number {
    int value, index;
    bool operator<(const Number& other)const {
        return value < other.value;
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(m);
    vector<ll> copy(m);
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> y[i];
        copy[i] = y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    unordered_map<int, int> map;
    for (int i = 0; i < m; i++) {
        bool flag = false;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (y[i] <= x[j]) {
                break;
            }
            flag = true;
            count++;
        }
        flag ? map[y[i]] : map[y[i]] = count;

    }
    for (auto& el : copy) {
        cout << map[el] << " ";
    }
    return 0;
}