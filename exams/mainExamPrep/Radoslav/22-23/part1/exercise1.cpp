#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main() {
    vector<ll> ivanchoStickers;
    vector<ll> brotherStickers;
    unordered_map<ll, ll> stickers;
    ll n;
    cin >> n;
    ll sticker;
    for (int i = 0; i < n; i++) {
        cin >> sticker;
        ivanchoStickers.push_back(sticker);
    }
    for (int i = 0; i < n; i++) {
        cin >> sticker;
        brotherStickers.push_back(sticker);
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        stickers[ivanchoStickers[i]]++;
        if (stickers[brotherStickers[i]] == 0) {
            count++;
        }
        else {
            stickers[brotherStickers[i]]--;
        }
    }
    cout << count;
    return 0;
}