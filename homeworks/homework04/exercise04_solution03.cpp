#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

/* 40/100 */

int main() {
    long long N, Q, K;
    cin >> N >> Q >> K;

    string command;
    long long key, val;

    list<pair<long long, long long>> hash;

    long long overloadCtr = 1;

    while (Q-- > 0) {
        cin >> command;

        if (command == "put") {
            cin >> key >> val;
            bool isFound = false;
            for (auto elem: hash) {
                if (elem.first == key) {
                    isFound = true;

                    hash.remove(elem);
                    hash.push_front(elem);

                    break;
                }
            } if (!isFound) {
                if (hash.size() == N) {
                    hash.pop_back();
                }

                hash.push_front(pair<long long, long long>(key ,val));
            }
        }
        else if (command == "get") {
            cin >> key;

            bool isFound = false;
            for (auto elem: hash) {
                if (elem.first == key) {
                    isFound = true;

                    hash.remove(elem);
                    hash.push_front(elem);

                    cout << elem.second << endl;

                    break;
                }
            } if (!isFound) {
                cout << "-1" << endl;
            }
        }

        if (overloadCtr++ % K == 0) {
            hash.pop_back();
        }
    }

    return 0;
}
