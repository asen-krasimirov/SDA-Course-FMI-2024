#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

int main() {
        int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    deque<int> result;
    int i = 0;
     while (i < n && arr[i] < 0) {
        cout << arr[i] << ' ';
        i++;
    }
    while (i < n && arr[i] > 0) {
        result.push_back(arr[i]);
        i++;
    }
    while (i < n) {
        if (!result.empty() && ((result.back() > 0 && arr[i] > 0) || (result.back() < 0 && arr[i] < 0))) {
            result.push_back(arr[i]);
            i++;
        }
        else if (result.empty() && arr[i]>0) {
            result.push_back(arr[i]);
            i++;
        }
        else if (result.empty() && arr[i] < 0) {
            cout << arr[i] << ' ';
            i++;
        }
        else if (!result.empty() && ((result.back() > 0 && arr[i] < 0))) {
            if (result.back() > -arr[i]) {
                i++;
            }
            else if (result.back() == -arr[i]) {
                result.pop_back();
                i++;
            }
            else {
                result.pop_back();
            }
        }
        else if (!result.empty() && ((result.back() < 0 && arr[i] > 0))) {
            result.push_back(arr[i]);
            i++;
        }
    }
    if (result.empty()) {
        cout << '\n';
    }
    else {
        while (!result.empty()) {
            cout << result.front() << ' ';
            result.pop_front();
        }
    }

}
