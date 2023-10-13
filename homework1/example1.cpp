#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string word;
    unsigned repetitions;
    char charToCount;

    std::cin >> word >> repetitions >> charToCount;

    unsigned counter = 0;

    unsigned wordLen = word.length();
    // unsigned countInWord;
    unsigned index = 0;
    while(index <= wordLen) {
        if (word[index++] == charToCount) counter++;
    }

    unsigned rem = repetitions / wordLen;
    unsigned remRepetitions = repetitions % wordLen;

    // counter *= rem >= 1 ? rem : 1;

    if (rem >= 1) {
        counter *= rem >= 1 ? rem : 1;
    } else {
        counter = 0;
    }

    for (unsigned i = 0; i < remRepetitions; ++i) {
        if (word[i] == charToCount) counter++;
    }

    std::cout << counter;

    return 0;
}
