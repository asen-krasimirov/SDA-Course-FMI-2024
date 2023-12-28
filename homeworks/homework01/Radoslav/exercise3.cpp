#include <bits/stdc++.h>
using namespace std;

int main() {
      size_t n, k;
    cin >> n >> k;
    vector<size_t> arr;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        arr.push_back(l);
    }
    size_t min = INT_MAX;
    sort(arr.begin(),arr.end());
    for (size_t i = 0; i < n; i++) {
        size_t diff = arr[k + i - 1] - arr[i];
        if (diff< min)
            min = diff;
    }
    cout << min;
    return 0;
}
