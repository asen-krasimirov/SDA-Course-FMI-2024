#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

#include <deque>
#include <queue>

using namespace std;

int N, M;

struct Tunnel {
    int to, distance, kg;
};

vector<deque<Tunnel>> graph;

int maxDistance;
int target, minWeight = -1;

bool thereIsPathForThisWeight(int kg) {
    const int n = graph.size();

    vector<int> distances(n, INT_MAX);
    vector<bool> visited(n, false);
    distances[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int newDist;
    int current;

    while (!pq.empty()) {

        current = pq.top().second;
        visited[current] = true;

        if (current == target) {
            break;
        }

        for (auto tunnel = graph[current].begin(); tunnel != graph[current].end(); ++tunnel) {

            if (tunnel->kg > kg || visited[tunnel->to]) {
                continue;
            }

            auto& distNeighbour = distances[tunnel->to];

            newDist = distances[current] + tunnel->distance;

            if (newDist < distNeighbour) {
                pq.emplace(newDist, tunnel->to);
                distNeighbour = newDist;
            }
        }

        while (!pq.empty() && visited[pq.top().second]) {
            pq.pop();
        }
    }

    return distances[target] <= maxDistance;
}

void binarySearchMinWeight(int lowerBound, int upperBound)
{
    if (upperBound < lowerBound) {
        return;
    }

    int mid = lowerBound + (upperBound - lowerBound) / 2;

    if (thereIsPathForThisWeight(mid)) {
        minWeight = mid;
        binarySearchMinWeight(lowerBound, mid - 1);
    }
    else {
        binarySearchMinWeight(mid + 1, upperBound);
    }
}

int main() {
    cin >> N >> M >> maxDistance;

    graph = vector<deque<Tunnel>>(N);

    target = N - 1;

    int start, maxWeight = INT_MIN;
    Tunnel tunnel;

    while (M--) {
        cin >> start >> tunnel.to >> tunnel.kg >> tunnel.distance;
        --start;
        --tunnel.to;
        graph[start].push_back(tunnel);
        maxWeight = max(tunnel.kg, maxWeight);
    }

    binarySearchMinWeight(0, maxWeight);

    cout << minWeight;

    return 0;
}
