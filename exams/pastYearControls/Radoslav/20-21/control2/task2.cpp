#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> arr2(1000000, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[arr[i]]++;
    }
    vector<bool> visited(1000000, false);
    for (int i = 0; i < 1000000; i++) {
        if (arr2[i] != 0 && !visited[i]) {
            visited[i] = true;
            cout << i << ' ';
        }
    }
    return 0;
}