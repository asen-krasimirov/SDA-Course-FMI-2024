#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

unordered_map<string, int> c1;
unordered_map<string, int> c2;
set<string> setset;

int main() {
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    stringstream ss1, ss2;
    ss1 << s1;
    ss2 << s2;

    string temp;

    while (ss1 >> temp) {
        c1[temp]++;
    }

    while (ss2 >> temp) {
        c2[temp]++;
    }

    for (auto s : c1) {
        if (s.second == 1 && c2[s.first] == 0) {
            setset.insert(s.first);
        }
    }

    for (auto s : c2) {
        if (s.second == 1 && c1[s.first] == 0) {
            setset.insert(s.first);
        }
    }

    for (auto s : setset) {
        cout << s << endl;
    }

    return 0;
}
