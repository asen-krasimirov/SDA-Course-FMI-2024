#include <iostream>
//#include <list>
#include <deque>

using namespace std;

/* 60/100 */

int main() {
    long long N, Q, K;
    cin >> N >> Q >> K;

    string command;
    long long key, val;

    long long vals[100001]{ 0 };
//    list<long long> keys;
    deque<long long> keys;

    for (int i = 1; i <= Q; ++i) {
        cin >> command;

        if (command == "put") {
            cin >> key >> val;
            if (N == 0) continue;

            if (vals[key] == 0) {
                if (keys.size() == N) {
                    vals[keys.back()] = 0;
                    keys.pop_back();
                }

                vals[key] = val;
                keys.push_front(key);
            }
            else {
                for (auto curKey = keys.begin(); curKey != keys.end(); ++curKey) {
                    if (*curKey == key) {
                        vals[key] = val;
                        keys.erase(curKey);
                        keys.push_front(key);
                        break;
                    }
                }
            }
        }
        else if (command == "get") {
            cin >> key;

            if (vals[key] == 0) {
                cout << "-1" << endl;
            }
            else {
                cout << vals[key] << endl;
                for (auto curKey = keys.begin(); curKey != keys.end(); ++curKey) {
                    if (*curKey == key) {
                        keys.erase(curKey);
                        keys.push_front(key);
                        break;
                    }
                }
            }
        }

        if (i % K == 0 && !keys.empty()) {
            vals[keys.back()] = 0;
            keys.pop_back();
        }
    }

    return 0;
}
