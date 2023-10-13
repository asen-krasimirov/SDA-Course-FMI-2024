#include <iostream>

void insertionSort(int arr[], int len) {
    unsigned swapsCtr = 0;

    for (int i = 0; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j--] > key) {
            arr[j + 1] = arr[j];
            swapsCtr++;
        }

        arr[j + 1] = key;
    }

    std::cout << "Swaps made: " << swapsCtr << std::endl;
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {34, 44, 27, 12, 37, 10, 47, 30, 20, 41, 15, 33, 14, 29};
    int len = 14;

    insertionSort(arr, len);
    printArray(arr, len);

    return 0;
}