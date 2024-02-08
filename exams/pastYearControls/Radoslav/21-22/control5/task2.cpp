#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        map[x]++;
    }
    int sum = 0;
    for (auto& el : map) {
        if (el.second % 2 != 0) {
            sum += (el.first * el.second);
        }
    }
    cout << sum;
    return 0;
}