#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Section {
    int bullentins, index;
    bool operator<(const Section& other)const {
        return bullentins == other.bullentins ? index < other.index : bullentins < other.bullentins;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Section> arr;
    vector<Section> copy;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back({ x,i });
        copy.push_back({ x,i });
    }
    sort(arr.begin(), arr.end());
    vector<int> temp(1000000);
    for (int i = 0; i < n; i++) {
        temp[arr[i].index] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << temp[copy[i].index] << " ";
    }
    return 0;
}
