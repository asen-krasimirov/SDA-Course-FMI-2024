#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

/* 40/100 */

int main() {
    int N;
    cin >> N;

    string command;

    list<int> notes;

    int note;

    for (int i = 0; i < N; ++i) {
        cin >> command;

        if (command == "add") {
            cin >> note;
            notes.push_back(note);
        }
        else if (command == "gun") {
            notes.pop_back();
        }
        else if (command == "milen") {
            int mid = notes.size() / 2;
            for (int j = 0; j < mid; ++j) {
                auto elem = notes.begin();
                notes.pop_front();
                notes.push_back(*elem);
            }
        }
    }

    cout << notes.size() << endl;
    for (auto elem: notes) {
        cout << elem << " ";
    }

    return 0;
}
