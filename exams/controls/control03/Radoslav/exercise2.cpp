#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

struct Node{
    int val;
    vector<Node*> children;
    
    int getCount(){
        int size=children.size();
        for(int i=0;i<children.size();i++){
            size+=children[i]->getCount();
        }
        return size;
    }
    
}nodes[1000000];

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        nodes[x].children.push_back(&nodes[y]);
    }
    for(int i=0;i<n;i++){
        cout<<nodes[i].getCount()<<' ';
    }
    return 0;
}
