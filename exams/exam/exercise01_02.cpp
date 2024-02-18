#include <bits/stdc++.h>
using namespace std;

/* Quadratic Solution (passes all tests) */

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        string str;
        cin >> str;
        unordered_map<char, int> um;

        for (int i = 0; i < str.size(); ++i) {
            um[str[i]]++;
        }

        bool isWordValid = false;

        for (auto e : um) {
            int isValid = 0;

            um[e.first]--;

            int ctr = -1;

            for (auto el : um) {
                if (um[e.first] == 0 && el.first == e.first) {
                    continue;
                }

                if (ctr == -1) {
                    ctr = el.second;
                }

                if (ctr == el.second) {
                    isValid++;
                }
            }

            if (isValid == um.size() || (um[e.first] == 0 && isValid == um.size() - 1)) {
                isWordValid = true;
                break;
            }

            um[e.first]++;
        }

        cout << isWordValid << endl;
    }


    return 0;
}
