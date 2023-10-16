#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> voters;
    vector<int> sortedIndexes(N);

    for (int i = 0; i < N; ++i) {
        int curVoters;
        cin >> curVoters;
        voters.push_back(pair<int, int>(curVoters, i));
    }

    sort(voters.begin(), voters.end());

    for (int i = 0; i < N; ++i) {
        sortedIndexes[voters[i].second] = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << sortedIndexes[i] << " ";
    }

    return 0;
}
