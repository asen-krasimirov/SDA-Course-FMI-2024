#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<int> v2(v);
    sort(v.begin(),v.end());
    int countLeft=0;
    for(int i=0;i<n;i++){
        if(v[i]==v2[i]){
        countLeft++;    
        }
        else{
            break;
        }
    }
    int countRight = 0;
    if(countLeft==v.size()){
        cout<<v.size()-countLeft;
        return 0;
    }
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==v2[i]){
            countRight++;
        }
        else {
            break;
        }
    }
    cout<<v.size()-(countLeft+countRight);
    return 0;
}
