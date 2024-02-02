#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        unordered_map<int, char> um;
        string str;
        cin >> str;

        for (int i = 0; i < str.size(); ++i) {
            um[str[i]]++;
        }

        unordered_map<int, int> us;

        int mostCommon = INT_MIN;

        int leastCommon = INT_MAX;

        for (auto e : um) {
            if (e.second > mostCommon) {
                mostCommon = e.second;
            } else if (e.second < leastCommon) {
                leastCommon = e.second;
            }

            us[e.second]++;
        }

        if ((mostCommon - 1 == leastCommon && us[mostCommon] == 1) || (leastCommon == 1 && us[leastCommon] == 1 && us.size() == 2)) {
            cout << 1 << endl;
        } else {
            if (leastCommon == INT_MAX) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
