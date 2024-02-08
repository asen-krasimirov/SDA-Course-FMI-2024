#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(1000000, 0);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        arr[value]++;
    }
    int m;
    cin >> m;
    int sum = 0;
    vector<bool> visited(1000000, false);
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        if (arr[value] != 0 && !visited[value]) {
            sum += value;
            visited[value] = true;
        }
    }
    cout << sum;
    return 0;
}