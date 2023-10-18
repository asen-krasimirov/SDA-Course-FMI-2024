#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool ternarySearch(vector<T> &arr, int left, int right, const T &value) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == value || arr[mid2] == value) {
            return true;
        }

        if (arr[mid1] > value) {
            return ternarySearch(arr, left, mid1 - 1, value);
        }
        else if (arr[mid1] < value && value < arr[mid2]) {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, value);
        }
        else {
            return ternarySearch(arr, mid2 + 1, right, value);
        }
    }

    return false;
}

template <typename T>
bool ternarySearchIterative(vector<T> &arr, int left, int right, const T &value) {
    while (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == value || arr[mid2] == value) {
            return true;
        }

        if (arr[mid1] > value) {
            right = mid1 - 1;
        }
        else if (arr[mid1] < value && value < arr[mid2]) {
            left = mid1 + 1;
            right = mid2 - 1;
        }
        else {
            left = mid2 + 1;
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 5, 3, 8, 7, 0, 4, 6, 9};

    sort(arr.begin(), arr.end());

    cout << "Recursive Implementation: " << endl;
    cout << ternarySearch(arr, 0, arr.size() - 1, 3) << endl;                   // true
    cout << ternarySearch<int>(arr, 0, arr.size() - 1, 3) << endl;              // true
    cout << ternarySearch(arr, 0, arr.size() - 1, 10) << endl;                  // false
    cout << ternarySearch<int>(arr, 0, arr.size() - 1, 10) << endl;             // false
    cout << "Iterative Implementation: " << endl;
    cout << ternarySearchIterative(arr, 0, arr.size() - 1, 3) << endl;          // true
    cout << ternarySearchIterative(arr, 0, arr.size() - 1, 4) << endl;          // true
    cout << ternarySearchIterative<int>(arr, 0, arr.size() - 1, 10) << endl;    // false

    return 0;
}
