#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool linearSearch(vector<T> &arr, const T &value) {
    for (auto elem: arr) {
        if (elem == value) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 5, 3, 8, 7, 0, 4, 6, 9};

    cout << linearSearch(arr, 3) << endl;          // true
    cout << linearSearch<int>(arr, 3) << endl;     // true
    cout << linearSearch(arr, 10) << endl;         // false
    cout << linearSearch<int>(arr, 10) << endl;    // false

    return 0;
}
