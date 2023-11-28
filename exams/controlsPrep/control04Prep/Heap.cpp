#include <vector>
#include <stdexcept>

using namespace std;

class Heap {
private:
    vector<int> heap;

    int getLeft(int idx) {
        return idx * 2 + 1;
    }

    int getRight(int idx) {
        return idx * 2 + 2;
    }

    int getParent(int idx) {
        return (idx - 1) / 2;
    }

    void shiftUp(int idx) {
        int parent = getParent(idx);

        while (heap[parent] < heap[idx]) {
            swap(heap[parent], heap[idx]);

            if (parent == 0) {
                break;
            }

            idx = parent;
            parent = getParent(idx);
        }
    }

    void shiftDown(int idx) {
        while (idx < heap.size() - 1) {
            int leftIdx = getLeft(idx);
            int rightIdx = getRight(idx);

            bool hasLeft = leftIdx < heap.size() - 1;
            bool hasRight = rightIdx < heap.size() - 1;

            if (hasRight && (heap[idx] < heap[leftIdx] || heap[idx] < rightIdx)) {
                if (heap[leftIdx] < heap[rightIdx]) {
                    swap(heap[idx], heap[rightIdx]);
                    idx = rightIdx;
                } else {
                    swap(heap[idx], heap[leftIdx]);
                    idx = leftIdx;
                }
            } else if (hasLeft && heap[idx] < heap[leftIdx]) {
                swap(heap[idx], heap[leftIdx]);
                idx = leftIdx;
            } else {
                break;
            }
        }
    }

public:
    bool empty() {
        return heap.empty();
    }

    void push(int elem) {
        heap.push_back(elem);
        shiftUp(heap.size() - 1);
    }

    void pop() {
        if (empty()) {
            throw invalid_argument("heap is empty");
        }

        if (heap.size() == 1) {
            heap = vector<int>();
        }

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        shiftDown(0);
    }

    int top() {
        if (empty()) {
            throw invalid_argument("heap is empty");
        }

        return heap[0];
    }
};