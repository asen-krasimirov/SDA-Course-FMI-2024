#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int encode(char c){
    if(c>='0' && c<='9'){
        return c-47;
    }
    if(c>='a' && c<='z'){
        return c-86;
    }
    if(c>='A' && c<='Z'){
        return c-28;
    }
    return 0;
}

char decode(int num){
    if(num>=1 && num<=10){
        return num+47;
    }
    if(num>=11 && num<=36){
        return num+86;
    }
    if(num>=37 && num<=62){
        return num+28;
    }
    return '/0';
}

int main() {
    int n;
    cin>>n;
    string str,strCopy;
    vector<int> v(n);
    cin>>str;
    for(int i=0;i<n;i++){
        v[i]=encode(str[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<decode(v[i]);
    }
    return 0;
}
