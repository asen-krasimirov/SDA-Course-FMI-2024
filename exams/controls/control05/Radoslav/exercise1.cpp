#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        unordered_map<string,int> s1;
        unordered_map<string,int> s2;
        for(int j=0;j<x;j++){
            string s;
            cin>>s;
            s1[s]++;
        }
        for(int j=0;j<y;j++){
            string s;
            cin>>s;
            s2[s]++;
        }
        bool flag=true;
        
        for(auto s: s2){
            if(s1[s.first]< s.second){
                flag=false;
            }
        }
        
        if(flag){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
