#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot  = arr[high];
    int i = low;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[j], arr[i++]);
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int randomPartition(vector<int>& arr, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[high], arr[random]);

    return partition(arr, low, high);
}

vector<int>& quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
//        int pi = partition(arr, low, high);
        int pi = randomPartition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

    return arr;
}

void printArray(vector<int>& arr) {
    for (auto num : arr) {
        std::cout << num << " ";
    }
}

int main() {
    vector<int> arr = {34, 44, 27, 12, 37, 10, 47, 30, 20, 41, 15, 33, 14, 29};

    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);

    return 0;
}
