#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<pair<vector<int>, int>>& g, vector<bool>& vis, int x, int myGroup) {
    queue<pair<int, int>> q;
    vis[x] = true;
    q.push({ x,0 });

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node != x && g[node].second == myGroup) {
            return dist;
        }

        for (auto& cur : g[node].first) {
            if (!vis[cur]) {
                vis[cur] = true;
                q.push({ cur,dist + 1 });
            }
        }
    }
    return -1;
}

void resetGraph(vector<bool>& vis){
    for(int i=0;i<vis.size();i++){
        vis[i]=false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].first.push_back(y);
        g[y].first.push_back(x);
    }

    vector<int> groups(n + 1);
    for (int i = 1; i <= n; i++) {
        int group;
        cin >> group;
        g[i].second = group;
    }

    int myGroup;
    cin >> myGroup;

    vector<bool> vis(n + 1, false);
    vector<int> res;

    for (int i = 1; i <= n; i++) {
        if (g[i].second == myGroup) {
            res.push_back(bfs(g, vis, i, myGroup));
            resetGraph(vis);
        }
    }
    sort(res.begin(),res.end());
    if(!res.empty()){
        cout<<res[0];
    }else{
        cout<<-1;
    }
    
    return 0;
}
