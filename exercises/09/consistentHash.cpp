#include <iostream>
#include <vector>
#include <set>
//#include <hash>

using namespace std;

vector<vector<int>> hash_table;

set<pair<string, int>> hash_area;

string md5(int x) {
    return to_string(x);
}

void init() {
    hash_table = vector<vector<int>>(20);

    for (int i = 0; i < 19; ++i) {
        hash_area.insert({md5(i), i});
    }
}

void add(int elem) {
    string hash = md5(elem);

    auto ub = hash_area.upper_bound({hash, 0});

    if (ub == hash_area.end()) {
        pair<string, int> first = *hash_area.begin();
        hash_table[first.second].push_back(elem);
        return;
    }

    pair<string, int> cell = *ub;
    hash_table[cell.second].push_back(elem);
}

void shrink(int n) {
    for (int i = 0; i < n; ++i) {
        string hash = md5(hash_table.size() - i);
        hash_area.erase({hash, hash_table.size() - i});
    }

    for (int i = 0; i < n; ++i) {
        for (int elem : hash_table[hash_table.size() - i]) {
            add(elem);
        }
    }

    hash_table.resize(hash_table.size() - n);
}

void expand(int n) {
    for (int i = 0; i < n; ++i) {
        string hash = md5(hash_table.size() + i);
        vector<int> new_cell;
        hash_table.push_back(new_cell);

        auto at_least = hash_area.lower_bound({hash, 0});
        pair<string, int> prev;

        if (at_least != hash_area.begin() && at_least != hash_area.end()) {
            prev = *(--at_least);
        } else {
            prev = *(--hash_area.rbegin());
        }

        vector<int> temp;

        for (int elem : hash_table[prev.second]) {
            temp.push_back(elem);
        }

        hash_table[prev.second].resize(0);

        for (int elem : temp) {
            add(elem);
        }

        hash_area.insert({hash, hash_table.size() + i});
    }

}

int main() {

//    cout << hash<int>(20);

    hash<int> ptr_hash;

    cout << ptr_hash(20);

    return 0;
}