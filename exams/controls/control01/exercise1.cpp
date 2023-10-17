#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> counter(256);
    vector<int> firstIndex(256);

    for (int i = 0; i < str.size(); ++i) {
        counter[str[i]] += 1;
        if (counter[str[i]] == 1) firstIndex[str[i]] = i;
    }

    vector<int> uniques;
    for (int i = 0; i < 256; ++i) {
        if (counter[i] == 1) uniques.push_back(firstIndex[i]);
    }

    sort(uniques.begin(), uniques.end());

    for (int i = 0; i < uniques.size(); ++i) {
        cout << uniques[i] << " ";
    }

    return 0;
}
