#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Lice {
    long index;
    long pristigane;
    long trygvane;
    long stol=-1;
    bool operator<(const Lice& other) const {
        if (pristigane == other.trygvane) {
            return trygvane < other.trygvane;
        }
        return pristigane < other.pristigane;
    }
    bool operator>(const Lice& other) const {
           return trygvane > other.trygvane;
    }
};

int main() {
    long n, t;
    cin >> n;
    vector<Lice> hora(n);
    for (int i = 0; i < n; i++) {
        hora[i].index = i;
        cin >> hora[i].pristigane >> hora[i].trygvane;
    }
    cin >> t;
    priority_queue<int,vector<int>, greater<int>> stolove;
    for (int i = 0; i < n; i++) {
        stolove.push(i);
    }
    sort(hora.begin(), hora.end());
    priority_queue<Lice,vector<Lice>,greater<Lice>> sednali;
    for (int i = 0; i < n; i++) {
        if (sednali.empty() || hora[i].pristigane < sednali.top().trygvane) {
            hora[i].stol=stolove.top();  
            stolove.pop();
            if (hora[i].index == t) {
                cout<<hora[i].stol;
                break;
            }
            sednali.push(hora[i]);
        }
        else {
            while (!sednali.empty() && sednali.top().trygvane <= hora[i].pristigane) {
                stolove.push(sednali.top().stol);
                sednali.pop();
            }
            hora[i].stol=stolove.top();  
            stolove.pop();
            if (hora[i].index == t) {
                cout<<hora[i].stol;
                break;
            }
            sednali.push(hora[i]);
        }
      
    }
    return 0;
}
