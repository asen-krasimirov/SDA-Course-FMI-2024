#include <iostream>
#include <vector>

using namespace std;

/* implementation by ViktorGV (github) */

class Heap {
private:
    vector<int> heap;

    int getLeft(int index) {
        return index * 2 + 1;
    }

    int getRight(int index) {
        return index * 2 + 2;
    }

    int getParent(int index) {
        return (index - 1) / 2;
    }

    void shiftUp(int index) {
        int parent = getParent(index);
        while (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);

            if (parent == 0) {  // parent <= 0
                break;
            }

            index = parent;
            parent = getParent(index);
        }
    }

    void shiftDown(int index) {
        while (index < heap.size() - 1) {
            int leftIndex = getLeft(index);
            int rightIndex = getRight(index);

            bool hasLeft = leftIndex < heap.size() - 1;
            bool hasRight = rightIndex < heap.size() - 1;

            if (hasRight && (heap[index] < heap[leftIndex] || heap[index] < heap[rightIndex])) {
                if (heap[leftIndex] < heap[rightIndex]) {
                    swap(heap[index], heap[rightIndex]);
                    index = rightIndex;
                } else {
                    swap(heap[index], heap[leftIndex]);
                    index = leftIndex;
                }
            } else if (hasLeft && heap[index] < heap[leftIndex]) {
                swap(heap[index], heap[leftIndex]);
                index = leftIndex;
            } else {
                break;
            }
        }
    }

    void shiftDownRecursive(int index) {
        int leftIndex = getLeft(index);
        int rightIndex = getRight(index);

        bool hasLeft = leftIndex < heap.size() - 1;
        bool hasRight = rightIndex < heap.size() - 1;

        if (hasRight && (heap[index] < heap[leftIndex] || heap[index] < heap[rightIndex])) {
            if (heap[leftIndex] < heap[rightIndex]) {
                swap(heap[index], heap[rightIndex]);
                shiftDownRecursive(rightIndex);

            } else {
                swap(heap[index], heap[leftIndex]);
                shiftDownRecursive(leftIndex);
            }
        } else if (hasLeft && heap[index] < heap[leftIndex]) {
            swap(heap[index], heap[leftIndex]);
            shiftDownRecursive(leftIndex);
        }
    }


public:

    void add(int element) {
        heap.push_back(element);
        shiftUp(heap.size() - 1);
    }

    int getMax() {
        if (!heap.empty()) {
//            throw invalid_argument("heap is empty");
        }

        return heap[0];
    }

    int pop() {
        if (!heap.empty()) {
//            throw invalid_argument("heap is empty");
        }

        if (heap.size() == 1) {
            heap = vector<int>();
        }

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        shiftDown(heap[0]);
    }


};