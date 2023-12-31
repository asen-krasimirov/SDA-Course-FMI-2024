#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Cell {
    int row, col, time;

    Cell(int r, int c, int t) : row(r), col(c), time(t) {}

    bool operator>(const Cell &other) const {
        return time > other.time;
    }
};

bool isInBounds(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

int dijkstra(vector<vector<char>> &maze, int startRow, int startCol) {
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<int>> distance(n, vector<int>(m, INF));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pq.push(Cell(startRow, startCol, 0));
    distance[startRow][startCol] = 0;

    while (!pq.empty()) {
        Cell current = pq.top();
        pq.pop();

        int row = current.row;
        int col = current.col;
        int time = current.time;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (!isInBounds(newRow, newCol, n, m)) {
                return time;
            }

            if (visited[newRow][newCol]) {
                continue;
            }

            visited[newRow][newCol] = true;
            int newTime = time + (maze[newRow][newCol] == '#' ? 1 : 0);
            pq.push(Cell(newRow, newCol, newTime));
        }
    }

    return INF;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }

    int maxTime = 0;
    int countMaxTimeCells = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == '.') {
                int time = dijkstra(maze, i, j);
                bool hasExited = time < INF;
                if (hasExited) {
                    if (time > maxTime) {
                        maxTime = time;
                        countMaxTimeCells = 1;
                    } else if (time == maxTime) {
                        countMaxTimeCells++;
                    }
                }
            }
        }
    }

    cout << countMaxTimeCells << endl;
    return 0;
}
