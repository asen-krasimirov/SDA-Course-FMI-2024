#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int>& arr,int n,int element,int d){
    int l=0,r=n,i=0;
    while(r>=l){
        int m=l+(r-l)/2; 
        if(arr[m]-element==d){
            return true;
        }
        
        if(arr[m]-element<d){
            l=m+1;
        }
        else {
            r=m-1;  
        }
    }
    return false;
}

int main() {
    int n,d;
    cin>>n>>d;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int count=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(binarySearch(arr,n-1,arr[i],d)){
            count++;
        }
    }
    cout<<count;
    return 0;
}
