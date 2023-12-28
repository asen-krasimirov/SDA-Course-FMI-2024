#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    unsigned exams;
    std::cin >> exams;

    while (exams-- > 0) {
        unsigned studentsCount;
        unsigned minFailed;
        // string students;
        std::cin >> studentsCount >> minFailed;
        char *students = new char[studentsCount];
        std::cin >> students;


        unsigned failedList[26]{0};

        for (unsigned i = 0; i < studentsCount; ++i){
            char student = students[i];
            if (student >= 'A' && student <= 'Z') {
                failedList[student - 'A'] += 1;
            }
        }

        for (unsigned i = 0; i < 26; ++i) {
            if (failedList[i] >= minFailed) {
                cout << 'A' + i;
            }
        }
        std::cout << endl;
        delete[] students;
    }

    return 0;
}
