#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<string, int> m1, m2;
set<string> res;

int main() {
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    stringstream ss1, ss2;
    ss1 << s1;
    ss2 << s2;

    string temp;

    while (ss1 >> temp) {
        m1[temp]++;
    }

    while (ss2 >> temp) {
        m2[temp]++;
    }

    for (auto elem : m1) {
        if (elem.second == 1 && m2.find(elem.first) == m2.end()) {
            res.insert(elem.first);
        }
    }

    for (auto elem : m2) {
        if (elem.second == 1 && m1.find(elem.first) == m1.end()) {
            res.insert(elem.first);
        }
    }

    for (auto elem : res) {
        cout << elem << endl;
    }

    return 0;
}
