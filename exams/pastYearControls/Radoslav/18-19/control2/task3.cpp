#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> count(1000000, 0);
    vector<int> visited(1000000);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        count[v[i]]++;
    }
    for (int i = 0; i <= 1000000; i++) {
        if (count[i] != 0 && !visited[i]) {
            cout << i << " ";
            visited[i] = true;
        }
    }

    return 0;
}