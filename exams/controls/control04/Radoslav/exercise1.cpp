#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;


int main() {
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    cout<<fixed<<setprecision(1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        if(maxHeap.empty()){
            maxHeap.push(value);
        }
        else if(value<maxHeap.top()){
            
            maxHeap.push(value);
        }
        else{
           minHeap.push(value);       
        }
        if(maxHeap.size()>minHeap.size()+1){
            int top=maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        if(minHeap.size()>maxHeap.size()+1){
            int top=minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
        if((maxHeap.size()==minHeap.size())){
            cout<<(double)(maxHeap.top()+minHeap.top())/2<<'\n';
        }
        else {
            double ans=minHeap.size() > maxHeap.size() ? (double)minHeap.top() : (double)maxHeap.top();
            cout<<ans<<'\n';
        }
    }
    return 0;
}
