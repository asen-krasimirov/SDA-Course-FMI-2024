#include <iostream>
#include <vector>

using namespace std;

/*
int findBiggestNumInVector(vector<int> &arr) {
    int biggest = -1316134912;
    for (int curNum : arr) {
        if (curNum > biggest) biggest = curNum;
    }

    return biggest;
}
*/

vector<int> &countingSort(vector<int> &arr) {
    vector<int> arrCpy;

    arrCpy.reserve(arr.size()); /* optimization */
    for (int i: arr) {
        arrCpy.push_back(i);
    }

    int *count = new int[256]{0};
    for (int i: arr) {
        count[i] = count[i] + 1;
    }

    for (int i = 1; i < 256; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[count[arrCpy[i] - 1]] = arrCpy[i];
        count[arrCpy[i]] = count[arrCpy[i]] - 1;
    }

    delete[] count;

    return arr;
}

void printArray(vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << " ";
    }
}

int main() {
    vector<int> arr = {34, 44, 27, 12, 37, 10, 47, 30, 20, 41, 15, 33, 14, 29};

    countingSort(arr);
    printArray(arr);

    return 0;
}
