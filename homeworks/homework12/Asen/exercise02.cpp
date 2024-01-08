#include <bits/stdc++.h>

using namespace std;

struct Key {
    size_t effort, line;
    long long price;

    bool operator<(const Key &other) const {
        return this->effort < other.effort || (this->effort == other.effort && this->price > other.price);
    }
};

const size_t MAX_SIZE = 2 * 1e5 + 5;
size_t parents[MAX_SIZE], depth[MAX_SIZE];

vector<pair<Key, pair<size_t, size_t>>> graph;

int Find(int v) {
    if (v == parents[v]) {
        return v;
    }

    return parents[v] = Find(parents[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }

        parents[b] = a;

        if (depth[a] == depth[b]) {
            depth[a]++;
        }
    }
}

void kruskal() {
    size_t u, v;
    sort(graph.begin(), graph.end());

    for (size_t i = 0; i < graph.size(); i++) {
        u = Find(graph[i].second.first);
        v = Find(graph[i].second.second);

        if (u != v) {
            cout << graph[i].first.line << '\n';
            Union(u, v);
        }
    }
}

int main() {
    size_t N, M, from, to, effort;
    long long price;

    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        cin >> from >> to >> effort >> price;
        graph.push_back({{effort, i + 1, price},
                         {from,   to}});
    }

    for (size_t i = 0; i < N; ++i) {
        parents[i] = i;
    }

    kruskal();

    return 0;
}
