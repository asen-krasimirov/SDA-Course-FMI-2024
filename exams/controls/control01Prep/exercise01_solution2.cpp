#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getIndex(vector<pair<int, int>> &arr, int idx) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i].second == idx) return i;
    }
    return - 1;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> voters;

    for (int i = 0; i < N; ++i) {
        int curVoters;
        cin >> curVoters;
        voters.push_back(pair<int, int>(curVoters, i));
    }

    sort(voters.begin(), voters.end());

    for (int i = 0; i < N; ++i) {
        cout << getIndex(voters, i) << " ";
    }

    return 0;
}
