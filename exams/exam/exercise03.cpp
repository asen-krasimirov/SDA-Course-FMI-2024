#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1000001;

int parents[MAX_V], depth[MAX_V];
vector<bool> cycles;

int Find(int a) {
    if (a == parents[a]) {
        return a;
    }

    return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) {
        return;
    }

    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    parents[b] = a;

    if (depth[a] == depth[b]) {
        depth[a]++;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, V, E, x, y;

    cin >> N;

    while (N--) {
        int cyclesCtr = 0;

        cin >> V >> E;
        cycles = vector<bool>(V, false);

        for (int i = 0; i < V; ++i) {
            parents[i] = i;
            depth[i] = 0;
        }

        for (int i = 0; i < E; ++i) {
            cin >> x >> y;

            if (parents[x] == parents[y]) {
                if (!cycles[parents[x]]) {
                    cycles[parents[x]] = true;
                    cyclesCtr++;
                }
            } else {
                Union(x, y);
            }
        }

        cout << cyclesCtr << endl;
    }

    return 0;
}
