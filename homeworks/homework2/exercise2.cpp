#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers;
    vector<int> sorted;

    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;

        numbers.push_back(number);
        sorted.push_back(number);
    }

    sort(sorted.begin(), sorted.end());

    bool sortedStarted = false;
    int startToSort = -1;
    int endToSort = -1;

    for (int i = 0; i < N; ++i) {
        if (numbers[i] != sorted[i]) {
            if (!sortedStarted) {
                startToSort = i;
                sortedStarted = true;
            }
            i++;
            while (numbers[i] != sorted[i] && i < N) {
                endToSort = i;
                i++;
            }
        }
    }

    if (startToSort >= 0) {
        cout << endToSort - startToSort + 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
