#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int& curr, int start, int end, int target) {
    int l = start, r = end;
    while (l <= r) {
        curr++;
        int mid = (l + r) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<int> indexes;
    vector<int> iterations;
    for (int i = 0; i < q; i++) {
        int target;
        cin >> target;
        int currIteration = 0;
        int index = binarySearch(arr, currIteration, 0, n - 1, target);
        indexes.push_back(index);
        iterations.push_back(currIteration);
    }
    for (auto& el : indexes) {
        cout << el << ' ';
    }
    cout << '\n';
    for (auto& el : iterations) {
        cout << el << ' ';
    }
    return 0;
}