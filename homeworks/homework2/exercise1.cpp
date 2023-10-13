#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int decode(char ch) {
    if ('0' <= ch && ch <= '9') {
        return ch - '0' + 1;
    }
    else if ('a' <= ch && ch <= 'z') {
        return ch - 'a' + 11;
    }
    else if ('A' <= ch && ch <= 'Z') {
        return ch - 'A' + 37;
    }

    return 0;
}

char encode(int n) {
    if (1 <= n && n <= 10) {
        return '0' + n - 1;
    }
    else if (11 <= n && n <= 36) {
        return 'a' + n - 11;
    }
    else if (37 <= n && n <= 62) {
        return 'A' + n - 37;
    }

    return '\0';
}

int main() {
    unsigned N;
    cin >> N;

    string players;
    cin >> players;

    vector<int> sorted;
    for (unsigned i = 0; i < N; ++i) {
        sorted.push_back(decode(players[i]));
    }

    sort(sorted.begin(), sorted.end());

    for (unsigned i = 0; i < N; ++i) {
        cout << encode(sorted[i]);
    }


    return 0;
}
