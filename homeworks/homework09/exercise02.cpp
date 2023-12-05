#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int s1Idx, curCtr, maxCtr = 0;

    for (int i = 0; i < s1.size(); ++i) {
        curCtr = 0;
        s1Idx = i;

        for (int j = 0; j < s2.size() && s1Idx < s1.size(); ++j, ++s1Idx) {
            if (s1[s1Idx] != s2[j]) {
                curCtr = 0;
            } else {
                curCtr++;
                maxCtr = max(maxCtr, curCtr);
            }
        }
    }

    cout << maxCtr;

    return 0;
}
