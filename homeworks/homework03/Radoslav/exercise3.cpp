#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long calculate(vector<long long>& arr,long long mid,int& currentCount){
    long long sum=0;
    for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                currentCount++;
                sum=0;
            }
            sum+=arr[i];
        }
    return sum;
}

int main() {
    int n,t;
    cin>>n>>t;
    vector<long long> arr;
    long long sum=0;
    long long highest=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        sum+=temp;
        arr.push_back(temp);
        if(temp>highest){
            highest=temp;
        }
    }
    long long low=highest,high=sum,result=0;
    while(low<=high){
        int currentCount=0;
        long long mid=low+(high-low)/2;
        long long currentSum=calculate(arr,mid,currentCount);
        if (currentSum != 0) {
            currentCount++;
        }
        if(currentCount>t){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
        if(currentCount==t){
            result=mid;
        }
    }
    cout<<result;
    return 0;
}
