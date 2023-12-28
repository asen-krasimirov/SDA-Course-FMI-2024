#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    long long n, q, k;
    cin >> n >> q >> k;
    deque<int> myDeque;
    vector<int> arr(10000, -1);
    string command;
    long long  count = 0;
    for (long long i = 0; i < q; i++) {
        cin >> command;
        if (count == k) {
            arr[myDeque.back()] = -1;
            myDeque.pop_back();
            count = 0;
        }
        if (command == "put") {
            count++;
            long long  key, value;
            cin >> key >> value;
            if (arr[key] == -1) {
                if (myDeque.size() == n) {
                    arr[myDeque.back()] = -1;
                    myDeque.pop_back();
                }
                arr[key] = value;
                myDeque.push_front(key);
            }
            else {
                arr[key] = value;
                for (auto it = myDeque.begin(); it != myDeque.end(); it++) {
                    if (*it == key) {
                        myDeque.erase(it);
                        myDeque.push_front(key);
                        break;
                    }
                }
            }

        }
        else if (command == "get") {
            count++;
            long long key;
            cin >> key;
            bool isFound = false;
            if (arr[key] != -1) {
                cout << arr[key] << '\n';
                for (auto it = myDeque.begin(); it != myDeque.end(); it++) {
                    if (*it == key) {
                        myDeque.erase(it);
                        myDeque.push_front(key);
                        isFound = true;
                        break;
                    }
                }
            }
            if (!isFound) {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
