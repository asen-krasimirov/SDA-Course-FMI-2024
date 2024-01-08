#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const size_t MAX_SIZE = 2 * 1e5 + 5;

size_t N, M, from, to, speed;
size_t counter, tempMax, tempMin;

size_t parent[MAX_SIZE], depth[MAX_SIZE];

vector<pair<size_t, pair<size_t, size_t>>> graph;
pair<size_t, size_t> balancedTime;

size_t Find(size_t x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

bool Union(size_t x, size_t y, size_t distance) {
    size_t u = Find(x);
    size_t v = Find(y);

    if (u == v) {
        return false;
    }

    tempMax = max(tempMax, distance - tempMin);
    counter++;
    parent[v] = u;
    return true;
}

void resetParents(const size_t &N) {
    for (size_t i = 1; i <= N; ++i) {
        parent[i] = i;
    }
}

void kruskal() {
    size_t u, v;
    sort(graph.begin(), graph.end());

    for (size_t i = 0; i < graph.size(); i++) {
        u = Find(graph[i].second.first);
        v = Find(graph[i].second.second);

        if (u != v) {
            Union(u, v, graph[i].first);
        }
    }
}

int main() {
    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> speed;
        graph.push_back({speed, {from, to}});
    }

    sort(graph.begin(), graph.end());

    balancedTime = {-1, MAX_SIZE};

    for (auto i = graph.begin(); i != graph.end(); ++i) {
        tempMax = 0;
        tempMin = i->first;
        counter = 1;
        bool flag = false;

        resetParents(N);

        for (auto j = i; j != graph.end(); ++j) {
            if (Union(j->second.first, j->second.second, j->first) &&
                tempMax > balancedTime.second) {
                flag = true;
                break;
            }
        }

        if (!flag && counter == N && tempMax < balancedTime.second) {
            balancedTime = {tempMin, tempMax};
        }
    }

    cout << balancedTime.first << " " << balancedTime.first + balancedTime.second;

    return 0;
}
