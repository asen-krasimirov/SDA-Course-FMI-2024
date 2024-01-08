#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int from, to;
    long long effort, profit;
    int index;

    bool operator<(const Node& other) {
          if(effort == other.effort){
            return profit > other.profit;
        }
        else
        {
            return effort < other.effort;
        }
    }
};

int find(int v, int* parent) {
    if (v == parent[v]) {
        return v;
    }

    return parent[v] = find(parent[v], parent);
}

bool connect(int from, int to, int* parent) {
    int findX = find(from, parent);
    int findY = find(to, parent);
    if (findX != findY) {
        parent[findX] = findY;
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> v;
    for (int i = 0; i < m; i++) {
        int from,to;
        long long effort, profit;
        cin >>  from>>to >> effort >> profit;
        v.push_back({ from,to,effort,profit,i});
    }

    int parent[n+1];

    sort(v.begin(), v.end());

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
        
    int counter=0;
    
    for (int i = 0; i < m && counter!=n-1; i++) {
        int to = v[i].to;
        int from = v[i].from;

        if (connect(from, to, parent)) {
            counter++;
            cout << v[i].index+1 << '\n';
        }
    }

    return 0;
}
