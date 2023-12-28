#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



pair<long long,long long> binarySearch(vector<pair<long long,long long>>& arr,long long start,long long end,long long target){
    long long l=0;
    long long r=end-1;
    while(l<=r){
        if(arr[l].first+arr[r].first==target){
            return pair(arr[l].second,arr[r].second);
        }
        if(arr[l].first+arr[r].first>target){
            r--;
        }
        else{
            l++;
        }
    }
    return pair(0,0);
}


int main() {
    long long t;
    cin>>t;
    vector<pair<long long,long long>> ans;
    for(int i=0;i<t;i++){
        long long x,n;
        cin>>x>>n;
        vector<pair<long long,long long>> arr(n);
        for(int i=0;i<n;i++){
             arr[i].second=i+1;
            cin>>arr[i].first;
        }
        sort(arr.begin(),arr.end());
        pair<long long,long long> temp=binarySearch(arr,0,n,x);
        if(temp.first>temp.second){
            swap(temp.first,temp.second);
        }
        cout<<temp.first<<' '<<temp.second<<'\n';
    }
    return 0;
}
