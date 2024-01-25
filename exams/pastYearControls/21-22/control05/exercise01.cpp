#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <unordered_map>

using namespace std;

unordered_map<string, int> um;
vector<string> v;

int main() {
    int N;
    cin >> N;

    v = vector<string>(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        um[v[i]]++;
    }

    for (string str : v) {
        cout << um[str] << " ";
    }

    return 0;
}
