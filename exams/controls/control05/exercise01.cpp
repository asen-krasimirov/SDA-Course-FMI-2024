#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>

using namespace std;

int main() {
    long long T, len1, len2;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> len1 >> len2;

        unordered_map<string, int> s1;
        unordered_map<string, int> s2;
        string str;

        for (int j = 0; j < len1; ++j) {
            cin >> str;

            s1[str]++;
        }

        for (int j = 0; j < len2; ++j) {
            cin >> str;

            s2[str]++;
        }

        bool isPossible = true;

        for (auto s : s2) {
            if (s1[s.first] < s.second) {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }

    return 0;
}
