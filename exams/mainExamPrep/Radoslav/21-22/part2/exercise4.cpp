#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;
ll ans = 0, n, k;


int cookedPancakes(vector<ll>& cooks, ll currTime) {
    ll count = 0;
    for (int i = 0; i < k; i++) {
        count += currTime / cooks[i];
        if (count >= n) {
            break;
        }
    }
    return count;
}
int main() {
    cin >> n >> k;
    ll minTime = 100000;
    ll maxTime = 0;
    vector<ll> cooks(k);
    for (int i = 0; i < k; i++) {
        cin >> cooks[i];
        if (cooks[i] > maxTime) {
            maxTime = cooks[i];
        }
        if (cooks[i] < minTime) {
            minTime = cooks[i];
        }
    }
    sort(cooks.begin(), cooks.end());
    ll l = minTime, r = minTime*n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (cookedPancakes(cooks,mid) >= n) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}