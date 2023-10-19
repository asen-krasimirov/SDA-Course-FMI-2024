#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
bool jumpSearch(vector<T> &arr, const T &value) {
    int jump = sqrt(arr.size());
    int start = 0;
    int end = start + jump;

    while (end < arr.size() && arr[end] <= value) {
        start = end;
        end = end + jump;

        if (end > arr.size() - 1) {
            end = arr.size();
        }
    }

    for (int i = start; i < end; ++i) {
        if (arr[i] == value) return true;
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 5, 3, 8, 7, 0, 4, 6, 9};

    sort(arr.begin(), arr.end());

    cout << jumpSearch(arr, 3) << endl;          // true
    cout << jumpSearch(arr, 4) << endl;          // true
    cout << jumpSearch<int>(arr, 10) << endl;    // false

    return 0;
}
