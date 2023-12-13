#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M, sIdx, eIdx;
vector<pair<int, int>> *adj;
vector<int> distTo;

int shortestPath(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    distTo[start] = 0;

//    queue<pair<int, int>> q;
//    q.push({0, start});

    while (!q.empty()) {
        int v = q.top().second;
        int distToV = q.top().first;
        q.pop();

        if (v == end) {
            return distToV;
        }

        int weightFromWToV;
        for (pair<int, int> w : adj[v]) {
            v = w.first;
            weightFromWToV = w.second;

            if (distToV + weightFromWToV < distTo[v]) {
                distTo[v] = distToV + weightFromWToV;
                q.push({distTo[v], v});
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    adj = new vector<pair<int, int>>[N];
    distTo = vector<int>(N, INT_MAX);

    int v, w, weight;
    for (int i = 0; i < M; i++) {
        cin >> v >> w >> weight;
        adj[v].push_back({w, weight});
        adj[w].push_back({v, weight});
    }

    cin >> sIdx >> eIdx;

    cout << shortestPath(sIdx, eIdx);

    return 0;
}
