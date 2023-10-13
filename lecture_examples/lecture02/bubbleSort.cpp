#include <iostream>

void bubbleSort(int arr[], int len) {
    unsigned swapsCtr = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                swapsCtr++;
            }
        }
    }

    std::cout << swapsCtr << std::endl;
}


void bubbleSort2(int arr[], int n){
    unsigned swapsCtr = 0;

    int i, j;
    for (i = 0; i < n-1; i++) {

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
//                swap(&arr[j], &arr[j+1]);
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

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
    int arr[] = { 34, 44, 27, 12, 37, 10, 47, 30, 20, 41, 15, 33, 14, 29 };
    int len = 14;

    bubbleSort(arr, len);
    printArray(arr, len);

    return 0;
}