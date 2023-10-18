#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool binarySearch(vector<T> &arr, int left, int right, const T &value) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            return true;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, left, mid - 1, value);
        }
        else {
            return binarySearch(arr, mid + 1, right, value);
        }
    }

    return false;
}

template <typename T>
bool binarySearchIterative(vector<T> &arr, int left, int right, const T &value) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            return true;
        }

        if (arr[mid] > value) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 5, 3, 8, 7, 0, 4, 6, 9};

    sort(arr.begin(), arr.end());

    cout << "Recursive Implementation: " << endl;
    cout << binarySearch(arr, 0, arr.size() - 1, 3) << endl;                    // true
    cout << binarySearch<int>(arr, 0, arr.size() - 1, 3) << endl;               // true
    cout << binarySearch(arr, 0, arr.size() - 1, 10) << endl;                   // false
    cout << binarySearch<int>(arr, 0, arr.size() - 1, 10) << endl;              // false
    cout << "Iterative Implementation: " << endl;
    cout << binarySearchIterative(arr, 0, arr.size() - 1, 3) << endl;           // true
    cout << binarySearchIterative(arr, 0, arr.size() - 1, 4) << endl;           // true
    cout << binarySearchIterative<int>(arr, 0, arr.size() - 1, 10) << endl;     // false

    return 0;
}
