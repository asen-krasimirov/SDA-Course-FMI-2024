#include <iostream>

void selectionSort(int arr[], int len) {
    unsigned swapsCtr = 0;

    for (int i = 0; i < len; ++i) {
        int minIdx = i;

        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;

            swapsCtr++;
        }
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

    selectionSort(arr, len);
    printArray(arr, len);

    return 0;
}