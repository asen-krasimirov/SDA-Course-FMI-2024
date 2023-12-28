#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
   long long n,p;
    cin>>n>>p;
    priority_queue<long long,vector<long long>, greater<long long>> pq;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        pq.push(value);
    }
    int count=0;
    bool flag=false;
    while(!pq.empty()){
        if(pq.top()>=p){
           cout<<count;
            flag=true;
            break;
        }
        count++;
        long long one=pq.top();
        pq.pop();
        if(!pq.empty()){
            long long two=pq.top();
           pq.pop();
            long long newOne=one+2*two;
           pq.push(newOne);
        } 
    }
    if(flag==false){
        cout<<-1;
    }
    
    return 0;
}
