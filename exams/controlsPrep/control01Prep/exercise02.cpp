#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned findBiggestElem(vector<unsigned> &arr) {
    unsigned biggest = 0;
    for (unsigned int num : arr) {
        if (num > biggest) biggest = num;
    }
    return biggest;
}

int main() {
    int n;
    cin >> n;
    vector<unsigned> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<unsigned> counter(findBiggestElem(arr) + 1);
    for (int i = 0; i < n; ++i) {
        counter[arr[i]]++;
    }

    for (int i = 0; i < counter.size(); ++i) {
        if (counter[i]) cout << i << " ";
    }

    return 0;
}
