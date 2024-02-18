#include <cmath>
#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    queue<int> q;
    unordered_map<int, int> map;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        map[num]++;
    }
    vector<int> v2;
    for (auto& el : v) {
        if (map[el] == 1) {
            v2.push_back(el);
        }
        else if (map[el] > 1) {
            map.erase(el);
            q.push(el);
        }
    }
    while (!q.empty()) {
        v2.push_back(q.front());
        q.pop();
    }
    for (auto& el : v2) {
        cout << el << " ";
    }
    return 0;
}




