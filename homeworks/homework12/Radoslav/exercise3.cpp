#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    int from,to,weight;
    bool operator<(const Edge& other)const {
        return weight<other.weight;
    }
};

int find(int v, vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }

    parent[v] = find(parent[v], parent);
    return parent[v];
}

bool connect(int from, int to, vector<int>& parent) {
    int findX = find(from, parent);
    int findY = find(to, parent);
    if (findX != findY) {
        parent[findX] = parent[findY];
        return true;
    }
    return false;
}

void restartParent(vector<int>& parent,int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<Edge> g;
    for(int i=0;i<m;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        g.push_back({from,to,weight});
    }
    
    vector<int> parent(n+1);
    
    sort(g.begin(),g.end(),std::less<Edge>());
    
    int minSpeed=0,maxSpeed=1000000;
    for(int i=0;i<m;i++){
        restartParent(parent,n);
        
        int count = 0;
        int currentMin = g[i].weight;
        int currentMax = g[i].weight;
        int diff = maxSpeed - minSpeed;
        for(int j=i;j<m;j++){
            if(connect(g[j].from,g[j].to,parent)){
                count++;
                currentMax = max(currentMax,g[j].weight);
            }
            if(diff <= currentMax-currentMin){
                break;
            }
        }
        
        if(count != n-1 || diff<= currentMax-currentMin)
            continue;
        
        minSpeed=currentMin;
        maxSpeed=currentMax;
    }
    cout<<minSpeed<<" "<<maxSpeed;
    return 0;
}
