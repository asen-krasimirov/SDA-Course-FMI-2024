#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

stack<char> res;
vector<string> input;
map<char,vector<char>> g;
vector<bool> visited(128,false);


void dfs(char c){
    visited[c]=true;
    
    if(g.count(c)){
        for(auto& el: g[c]){
            if(!visited[el]){
                dfs(el);
            }
        }
    }
    res.push(c);
}

void topoSort(){
    for(auto& el: g){
        if(!visited[el.first]){
            dfs(el.first);
        }
    }
}

int main() {
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        input.push_back(tmp);
    }
    
    for(int i=0;i<n-1;i++){
        string first=input[i];
        string second=input[i+1];
        
        int len=min(first.size(),second.size());
        for(int j=0;j<len;j++){
            if(first[j]!=second[j]){
                g[first[j]].push_back(second[j]);
                break;
            }
        }
        
    }
      
    topoSort();
    
   while(!res.empty()){
       cout<<res.top()<<' ';
       res.pop();
   }
    
    
    return 0;
}
