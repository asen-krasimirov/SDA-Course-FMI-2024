#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<bool>& visited, vector<vector<int>>& g, int node){
    visited[node]=true;
    int ans=1;
    for(auto& el:g[node]){
        if(!visited[el]){
            ans+=dfs(visited,g,el);
        }
    }
    return ans;
}

int main() {
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n,m,k,l;
        cin>>n>>m>>k>>l;
        vector<vector<int>> g(n+1);
        for(int j=0;j<m;j++){
           int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> components;
        vector<bool> visited(n+1);
        
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                components.push_back(dfs(visited,g,j));
            }    
        }
        long long ans=0;
        for(int j=0;j<components.size();j++){
           ans+=min((components[j]-1)*l+k,components[j]*k); 
        }
        cout<<ans<<'\n';
    }
    return 0;
}
