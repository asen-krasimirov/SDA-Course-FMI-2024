#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

int Q, V, E, start;
vector<vector<int>> adj;
vector<bool> visited;

const int MAX = 1001;
const int INF = 1e6;

int distTo[MAX];

void findDists(int s) {
    visited[s] = true;

    distTo[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        q.pop();

        for (auto n : adj[s]) {
            if (!visited[n]) {
                visited[n] = true;
                distTo[n] = distTo[s] + 1;
                q.push(n);
            }
        }
    }
}

int main() {
    cin >> Q;

    while (Q--) {
        cin >> V >> E;
        V++;

        adj = vector<vector<int>>(V, vector<int>());
        visited = vector<bool>(V, false);

        for (int i = 0; i < MAX; ++i) {
            distTo[i] = INF;
        }

        for (int i = 0; i < E; ++i) {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cin >> start;

        for (int i = 1; i <= V; ++i) {
            if (!visited[i]) {
                findDists(start);
            }
        }

        for (int i = 1; i < V; ++i) {
            if (i == start) {
                continue;
            }

            int x = distTo[i];

            if (x != INF) {
                cout << x * 6 << " ";
            } else {
                cout << -1 << " ";
            }
        }

        cout << endl;
    }
    return 0;
}
