#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    vector<int> sorted;

    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            sorted.push_back(arr[left++]);
        } else {
            sorted.push_back(arr[right++]);
        }
    }

    while(left <= mid) {
        sorted.push_back(arr[left++]);
    }

    while (right <= end) {
        sorted.push_back(arr[right++]);
    }

    for (int i = start; i <= end; ++i) {
        arr[i] = sorted[i - start];
    }
}

vector<int>& mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    return arr;
}

vector<int> sort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int main() {

    return 0;
}