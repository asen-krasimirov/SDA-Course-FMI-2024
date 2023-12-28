#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


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

            bool found = false;
            long long pos = 0;
            for (auto elem: hash) {
                if (elem.first == key) {
                    found = true;

                    auto position = hash.begin();
                    advance(position, pos);
                    hash.erase(position);

                    hash.push_front(pair<long long, long long>(key, val));
                    break;
                }

                pos++;
            } if (!found) {
                if (hash.size() == N) {
                    hash.pop_back();
                }

                hash.push_front(pair<long long, long long>(key, val));
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

                    auto position = hash.begin();
                    advance(position, pos);
                    hash.erase(position);

                    hash.push_front(pair<long long, long long>(key, val));

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
