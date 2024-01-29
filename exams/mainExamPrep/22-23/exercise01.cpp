#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// #include <unordered_map>

using namespace std;


typedef long long ll;

ll N, x;

// unordered_map<int, int> stickers;

vector<pair<ll, ll>> stickers;
ll boiCtr = 0;

void bs(ll toFind, ll curDay) {
    ll l = 0, r = stickers.size(), m;

    while (l <= r) {
        m = l + (r - l) / 2;
//        m = (l + r) / 2;

        if (stickers[m].first == toFind && stickers[m].second > -1 && curDay >= stickers[m].second) {
            stickers[m].second = -1;
            // boiCtr--;
            return;
        }

        if (stickers[m].first == toFind && stickers[m].second == -1) {
            while (m + 1 < stickers.size()) {
                m++;
                if (stickers[m + 1].first == toFind) {
                    break;
                }
            }
        }

        if (stickers[m].first == toFind && stickers[m].second == -1) {
            while (m - 1 < stickers.size()) {
                m++;
                if (stickers[m + 1].first == toFind) {
                    break;
                }
            }
        }


        if (stickers[m].first > toFind) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    boiCtr++;
}

int main() {
    cin >> N;
    // boiCtr = N;

    for (ll i = 0; i < N; ++i) {
        cin >> x;
        stickers.push_back({x, i});
    }

    sort(stickers.begin(), stickers.end());

    // for (int i = 0; i < N; ++i) {
    // cout << "( " << stickers[i].first << ", " << stickers[i].second << " )" << " ";
    // }

    // cout << endl;

    for (ll i = 0; i < N; ++i) {
        cin >> x;
        // cout << "( " << x << ", " << i << " )" << " ";

        bs(x, i);
    }

    cout << boiCtr;

    return 0;
}