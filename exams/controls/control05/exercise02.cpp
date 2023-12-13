#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, y, Q;
vector<int> *adj;

void dfs(int v, int component, vector<bool> &visited, vector<int> &components) {
    visited[v] = true;
    components[v] = component;

    for (int n : adj[v]) {
        if (!visited[n]) {
            dfs(n, component, visited, components);
        }
    }
}

void separateComponents(vector<bool> &visited, vector<int> &components) {
    int curComp = 1;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, curComp, visited, components);
            curComp++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    adj = new vector<int>[N + 1];

    vector<bool> visited(N + 1);
    vector<int> components(N + 1);

    for (int i = 0; i < M; ++i) {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    separateComponents(visited, components);

    cin >> Q;

    for (int i = 0; i < Q; ++ i) {
        cin >> x >> y;
        bool areEqual = components[x] == components[y];
        cout << areEqual;
        cout <<  " ";
    }

    return 0;
}
