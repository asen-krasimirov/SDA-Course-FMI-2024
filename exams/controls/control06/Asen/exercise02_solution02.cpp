#include <bits/stdc++.h>
using namespace std;

/* 100/100 solution */

const int N = 100001;
pair<long, int> dist[N];
vector<pair<int, int>>adjacencyList[N];

void shortestPathDijkstra(int v)
{
    for (int i = 0; i < N; i++) {
        dist[i].first = LONG_MAX;
        dist[i].second = 0;

    }

    dist[v].first = 0;
    dist[v].second = 1;


    priority_queue< pair<long, int>, vector <pair<long, int>>, greater<pair<long, int>> > pq;
    pq.push({ 0,v });

    while (!pq.empty())
    {
        int current = pq.top().second;
        long costToCurrent = pq.top().first;
        pq.pop();

        if (costToCurrent > dist[current].first) continue;


        for (pair<int, int> neighbour : adjacencyList[current])
        {

            int child = neighbour.first;
            long costToChildOfCurrent = neighbour.second;

            if (dist[child].first > costToCurrent + costToChildOfCurrent)
            {
                dist[child].first = costToCurrent + costToChildOfCurrent;
                dist[child].second = dist[current].second;
                pq.push({ costToChildOfCurrent + costToCurrent, child });
            }

            else if (dist[child].first == costToCurrent + costToChildOfCurrent) {
                dist[child].second = (dist[child].second + dist[current].second) % 1000000007;
            }

        }
    }

}

int main()
{
    int numberOfEdges = 0, numberOfVertices = 0, costToChildOfCurrent = 0;
    int from = 0, to = 0;
    cin >> numberOfVertices >> numberOfEdges;
    while (numberOfEdges)
    {
        cin >> from >> to >> costToChildOfCurrent;
        adjacencyList[from].push_back({ to, costToChildOfCurrent });
        numberOfEdges--;
    }

    shortestPathDijkstra(1);

    if (dist[numberOfVertices].second != 0)
        cout << dist[numberOfVertices].first << " " << dist[numberOfVertices].second;
    else
        cout << -1 << " " << 0;


    return 0;
}
