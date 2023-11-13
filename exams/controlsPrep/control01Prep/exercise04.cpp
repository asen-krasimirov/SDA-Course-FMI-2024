#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    vector<int> arr1Counter(100001);
    vector<int> arr2Counter(100001);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        arr1Counter[num]++;
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        arr2Counter[num]++;
    }

    int sum = 0;
    for (int i = 0; i < 100001; ++i) {
        if (arr1Counter[i] && arr2Counter[i]) sum += i;
    }

    cout << sum;

    return 0;
}
