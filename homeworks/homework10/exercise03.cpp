#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>

using namespace std;

int N;
stack<char> result;
vector<string> inputStrings;
map<char, vector<char>> charMap;
vector<bool> visited(128, false);

void dfs(char c) {
    visited[c] = true;

    if (charMap.count(c)) {
        for (auto &elem: charMap[c]) {
            if (!visited[elem]) {
                dfs(elem);
            }
        }
    }

    result.push(c);
}

void topoSort() {
    for (auto &elem: charMap) {
        if (!visited[elem.first]) {
            dfs(elem.first);
        }
    }
}

int main() {
    cin >> N;

    string tmp;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        inputStrings.push_back(tmp);
    }

    for (int i = 0; i < N - 1; i++) {
        string first = inputStrings[i];
        string second = inputStrings[i + 1];

        int len = min(first.size(), second.size());
        for (int j = 0; j < len; j++) {
            if (first[j] != second[j]) {
                charMap[first[j]].push_back(second[j]);
                break;
            }
        }

    }

    topoSort();

    while (!result.empty()) {
        cout << result.top() << ' ';
        result.pop();
    }

    return 0;
}
