#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> arr2(1000000, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[arr[i]]++;
    }
    for (int i = 1000000; i >= 0; i--) {
        if (arr2[i] != 0) {
            for (int j = 0; j < arr2[i]; j++) {
                cout << i << " ";
            }
        }
    }
    return 0;
}
