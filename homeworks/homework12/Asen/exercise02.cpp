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
vector<pair<Key, pair<size_t, size_t>>> graph;
size_t parent[MAX_SIZE], depth[MAX_SIZE];

int Find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int root1 = Find(x);
    int root2 = Find(y);
    if(root1 == root2) {
        return;
    }
    if(depth[root1] > depth[root2])
        swap(root1, root2);
    if(depth[root1] == depth[root2]) {
        depth[root2]++;
    }
    parent[root1] = root2;
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
        parent[i] = i;
    }

    kruskal();

    return 0;
}
