#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <set>

using namespace std;

int main() {
    int N, bestFriend, curElem;

    cin >> curElem >> N;

    set<int> team;
    team.insert(curElem);

    for (int i = 0; i < N; ++i) {
        cin >> bestFriend >> curElem;

        if (team.find(bestFriend) != team.end()) {
            team.insert(curElem);
        }
    }

    cout << team.size();

    return 0;
}
