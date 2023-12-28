#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> studentsProjects(N);

    for (int i = 0; i < N; ++i) {
        cin >> studentsProjects[i];
    }

    sort(studentsProjects.begin(), studentsProjects.end());

    int validPairs = 0;
    for (int i = 0; i < N; ++i) {
        if (binary_search(studentsProjects.begin(), studentsProjects.end(), studentsProjects[i] - D)) validPairs++;
    }

    cout << validPairs;

    return 0;
}
