#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int E, T, x, y;
const int MAX = 200001;

struct Node {
    vector<Node *> nodes;
    int val;

} arr[MAX];

int getSum(Node *node) {
    int sum = 0;

    for (auto n : node->nodes) {
        sum += n->val;
        sum += getSum(n);
    }

    return sum;
}

int main() {
    cin >> E >> T;

    for (int i = 0; i < MAX; ++i) {
        arr[i].val = i;
    }

    for (int i = 0; i < E; ++i) {
        cin >> x >> y;

        arr[x].nodes.push_back(&arr[y]);
    }

    for (int i = 0; i < T; ++i) {
        cin >> x;

        cout << getSum(&arr[x]) << endl;
    }

    return 0;
}
