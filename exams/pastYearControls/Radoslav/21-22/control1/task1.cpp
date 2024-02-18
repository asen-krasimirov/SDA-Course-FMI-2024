#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    vector<int> sorted;
    while (left <= mid && right <= end) {
        if (arr[left] < arr[right]) {
            sorted.push_back(arr[left++]);
        }
        else {
            sorted.push_back(arr[right++]);
        }
    }
    while (left <= mid) {
        sorted.push_back(arr[left++]);
    }
    while (right <= end) {
        sorted.push_back(arr[right++]);
    }
    for (int i = start; i <= end; i++) {
        arr[i] = sorted[i - start];
    }
}
void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[i + 1]) {
            cout << arr[i] << ' ';
        }
    }
    return 0;
}