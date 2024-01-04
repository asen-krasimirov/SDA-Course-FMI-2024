#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Tunnel {
    long long to, kg, battery;
};

long long djikstra(vector<vector<Tunnel>>& g, int start, int end, int maxWeight) {
    vector<long long> distances(g.size(), LONG_LONG_MAX);
    distances[start] = 0;
    vector<bool> visited(g.size(), false);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({ 0,start });

    while (!pq.empty()) {
        long long currentNode = pq.top().second;
        long long currentWeight = pq.top().first;
        pq.pop();

        if (visited[currentNode] == true) {
            continue;
        }

        visited[currentNode] = true;


        for (auto& n : g[currentNode]) {
             if (n.kg > maxWeight) {
                continue;
            }
            
            long long nextNode = n.to;
            long long dist = n.kg;


            long long total = currentWeight + n.battery;

            if (distances[nextNode] > total) {
                distances[nextNode] = total;
                pq.push({ total,nextNode });
            }
        }
    }
    return distances[end];
}

long long binarySearchOnAnswer(long long minWeight, long long maxWeight,long long maxBatteryToUse, long long n,
    vector<vector<Tunnel>>& g) {
    long long l = minWeight, r = maxWeight;
    long long best = -1;
    while (l <= r) {
        long long mid = (l+r)/ 2;
        long long currentDistance = djikstra(g, 1, n, mid);
        if (currentDistance <= maxBatteryToUse) {
            best = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return best;
}


int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<vector<Tunnel>> graph(n + 1);
    long long maxWeight = 0;
    for (long long i = 0; i < m; i++) {
        long long from, to, kg, battery;
        cin >> from >> to >> kg >> battery;

        if (maxWeight < kg) {
            maxWeight = kg;
        }

        graph[from].push_back({ to,kg,battery });
    }
    cout << binarySearchOnAnswer(1, maxWeight, k, n, graph);

    return 0;
}
