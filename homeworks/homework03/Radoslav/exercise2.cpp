#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculate(vector<int>& arr,int min,int max){
    auto upperbound=upper_bound(arr.begin(),arr.end(),max);
    auto lowerBound=lower_bound(arr.begin(),arr.end(),min);
    return upperbound-lowerBound;
}


int main() {
    int n,q;
    cin>>n>>q;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<q;i++){
        int min,max;
        cin>>min>>max;
        if(min>max){
            cout<<0<<'\n';
        }
        else {
            cout<<calculate(arr,min,max)<<'\n';
            }
    }
    return 0;
}
