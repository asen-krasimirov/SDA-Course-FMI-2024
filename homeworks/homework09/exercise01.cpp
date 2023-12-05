#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>

using namespace std;


int main() {
    string s1, s2, sub;
    cin >> s1 >> s2;

    unordered_map<string, int> um;

    for (int i = 0; i < s2.size() - s1.size() + 1; ++i) {
        sub = s2.substr(i, s1.size());

        if (um.find(sub) == um.end()) {
            um[sub] = 0;
        }

        um[sub]++;
    }

    cout << um[s1];

    return 0;
}
