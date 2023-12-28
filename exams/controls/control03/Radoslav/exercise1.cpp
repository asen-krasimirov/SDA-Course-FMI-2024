#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int> v(k);
        for(int i=0;i<k;i++){
            
            cin>>v[i];
        }
        stack<int> st;
        bool flag=false;
        for(int i=0;i<k;i++){
            if (!st.empty() && v[i] < 0 && v[i] * -1 == st.top()) {
                st.pop();
            }
            else {
                st.push(v[i]);
            }
        }
        if(st.empty()){
            cout<<"YES"<<'\n';
            continue;
        }
        else if(flag==false){
              cout<<"NO\n";
        }
    }
    return 0;
}
