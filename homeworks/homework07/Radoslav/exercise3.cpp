#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;


int main() {
    long long n, k;
    cin >> n >> k;
    queue<long long> q;
    set<long long> s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    for (int i = 0; i < k; i++) {
        int value;
        cin>>value;
        q.push(value);
        s.erase(value);
    }
    auto it=s.begin();
    while(!q.empty() && it!=s.end()){
        if(q.front()<*it){
            cout<<q.front()<<' ';
            q.pop();
        }
        else{
            cout<<*it<<' ';
            it++;
        }
    }
     while(it!=s.end()){
        cout<<*it++<<' ';
    }
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
    return 0;
}
