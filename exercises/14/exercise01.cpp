#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node *, Node *> visited;

    Node *cloneGraph(Node *node) {
        if (node == nullptr) { return nullptr; }
        if (visited[node] != nullptr) { return visited[node]; }
        Node *newNode = new Node(node->val);
        visited[node] = newNode;
        for (auto *elem: node->neighbors) {
            if (visited.find(elem) == visited.end()) {
                newNode->neighbors.push_back(cloneGraph(elem));
            }
            else { newNode->neighbors.push_back(visited[elem]); }
        }
        return newNode;
    }
};
