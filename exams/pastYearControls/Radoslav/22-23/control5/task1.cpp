#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    string s1;
    unordered_map<string, int> map;
    while (cin >> s1) {
        map[s1]++;
    }
    vector<string> words;
    for (auto& el : map) {
        if (el.second == 1) {
            words.push_back(el.first);
        }
    }
    sort(words.begin(), words.end());
    for (auto& word : words) {
        cout << word << "\n";
    }
    return 0;
}