#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    long long N, Q, K;
    cin >> N >> Q >> K;

    string command;
    long long key, val;

    vector<pair<long long, long long>> hash;

    long long overloadCtr = 1;

    while (Q-- > 0) {
        cin >> command;

        if (command == "put") {
            cin >> key >> val;

            bool found = false;
            long long pos = 0;
            for (auto elem: hash) {
                if (elem.first == key) {
                    found = true;

                    auto positionItr = hash.begin();
                    for (int i = 0; i < pos; ++i) positionItr++;
                    hash.erase(positionItr);

                    hash.insert(hash.begin(), pair<long long, long long>(key, val));
                    break;
                }

                pos++;
            } if (!found) {
                if (hash.size() == N) {
                    hash.pop_back();
                }

                hash.insert(hash.begin(), pair<long long, long long>(key, val));
            }

        }
        else if (command == "get") {
            cin >> key;

            bool found = false;
            long long pos = 0;
            for (auto elem: hash) {
                if (elem.first == key) {
                    found = true;

                    val = elem.second;

                    cout << val << endl;

                    auto positionItr = hash.begin();
                    for (int i = 0; i < pos; ++i) positionItr++;
                    hash.erase(positionItr);

                    hash.insert(hash.begin(), pair<long long, long long>(key, val));
                    break;
                }

                pos++;
            } if (!found) {
                cout << "-1" << endl;
            }

        }

        if (overloadCtr++ % K == 0) {
            hash.pop_back();
        }
    }

    return 0;
}
