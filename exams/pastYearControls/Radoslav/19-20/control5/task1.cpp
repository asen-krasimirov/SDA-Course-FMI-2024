#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++) {
        string city;
        int tax;
        cin >> city >> tax;
        map[city] = tax;
    }
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        string city;
        cin >> city;
        if (map.find(city) != map.end()) {
            sum += map[city];
        }
    }
    cout << sum;
    return 0;
}
