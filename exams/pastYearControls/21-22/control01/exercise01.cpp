#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> counter(70001, 0);

int main() {
    int N, x;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        counter[x]++;
    }

    for (int i = 0; i < 70001; ++i) {
        if (counter[i] > 0) {
            cout << i << " ";
        }
    }

    return 0;
}
