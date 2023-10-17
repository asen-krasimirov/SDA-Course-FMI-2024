#include <iostream>
#include <vector>

using namespace std;

vector<int> &countingSort(vector<int> &arr) {
    vector<int> arrCpy(arr.size());

    int max = arr[0];
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > max) max = arr[i];
        arrCpy[i] = arr[i];
    }

//    int *count = new int[max + 1]{0};
    vector<int> count(max + 1);
    for (int i: arr) {
        count[i] = count[i] + 1;
    }

    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[count[arrCpy[i]] - 1] = arrCpy[i];
        count[arrCpy[i]] = count[arrCpy[i]] - 1;
    }

//    delete[] count;

    return arr;
}

void printArray(vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << " ";
    }
}

int main() {
//    vector<int> arr = {34, 44, 27, 12, 37, 10, 47, 30, 20, 41, 15, 33, 14, 29};
    vector<int> arr = {5, 7, 6};

    countingSort(arr);
    printArray(arr);

    return 0;
}
