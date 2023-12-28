#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& g,vector<int>& components,vector<bool>& vis,int node,int& compIndex){
    for(auto el: g[node]){
        if(!vis[el]){
             components[el]=compIndex;
            vis[el]=true;
            dfs(g,components,vis,el,compIndex);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int compIndex=1;
    vector<int> components(1000000);
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(g,components,vis,i,compIndex);
            compIndex++;
        }
    }
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        cout<<(components[x]==components[y])<<' ';
    }
    
    return 0;
}
