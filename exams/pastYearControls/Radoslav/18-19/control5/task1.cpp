#include <bits/stdc++.h>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v;
    unordered_set<int> s;
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        map[id]++;
        s.insert(id);
    }
    int orders = 0, counter = 0;
    for (auto& el : map) {
        if (el.second % 10 == 0) {
            s.erase(el.first);
        }

        orders += el.second % 10;
    }

    cout << s.size() << " " << orders;
    return 0;
}