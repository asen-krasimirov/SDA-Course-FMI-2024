#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    cin>>n;
    unordered_map<int,int> um;
    int res=1000000;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        if(um.find(value)!=um.end()){
            res=min(i-um[value],res);
        }
        um[value]=i;
    }
    cout<<res;
    return 0;
}
