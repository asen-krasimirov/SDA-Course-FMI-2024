#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> strs;
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
        map[s]++;
    }

    for (auto& str : strs) {
        cout << map[str] << " ";
    }
    return 0;
}
