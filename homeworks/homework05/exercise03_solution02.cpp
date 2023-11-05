#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

/* not 100/100 */

int main() {
    int N;
    cin >> N;

    queue<int> players;

    int curPlayer, curFront;
    for (int i = 0; i < N; ++i) {
        cin >> curPlayer;
        players.push(curPlayer);
    }

    int dayCtr = 0;

    while (true) {

        int size = players.size();

        curPlayer = players.front();
        players.pop();
        players.push(curPlayer);

        if (players.empty()) {
            break;
        }

        for (int i = 1; i < size; ++i) {
            curFront = players.front();
            players.pop();

            if (curFront <= curPlayer) {
                players.push(curFront);
                curPlayer = curFront;

            }
            else {
                while (!players.empty()) {
                    curPlayer = players.front();
                    players.pop();

                    if (curPlayer < curFront) {
                        break;
                    }
                }

                players.push(curPlayer);
                i++;
            }
        }

        if (size == players.size()) {
            break;
        }

        dayCtr++;
    }

    cout << dayCtr;

    return 0;
}
