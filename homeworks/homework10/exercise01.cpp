#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dRow[] = {0, -1, 0, 1};
int dCol[] = {-1, 0, 1, 0};

bool isValid(int row, int col) {
    if (row < 0 || row >= N) {
        return false;
    }

    if (col < 0 || col >= N) {
        return false;
    }

    return true;
}

void DFS(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col,
         int &maxRow, int &maxCol, int &minRow, int &minCol) {
    visited[row][col] = true;

    maxCol = max(maxCol, col);
    maxRow = max(maxRow, row);
    minRow = min(minRow, row);
    minCol = min(minCol, col);

    for (int i = 0; i < 4; i++) {
        int adjX = row + dRow[i];
        int adjY = col + dCol[i];

        if (isValid(adjX, adjY) && matrix[adjX][adjY] == 1 && !visited[adjX][adjY]) {
            DFS(matrix, visited, adjX, adjY, maxRow, maxCol, minRow, minCol);
        }
    }
}

int main() {
    cin >> N;

    vector<vector<int>> adjMatrix(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<long long> res;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && adjMatrix[i][j] == 1) {
                int maxRow = INT_MIN, maxCol = INT_MIN;
                int minRow = INT_MAX, minCol = INT_MAX;

                DFS(adjMatrix, visited, i, j, maxRow, maxCol, minRow, minCol);

                res.push_back(
                        (maxRow - minRow + 1) * (maxCol - minCol + 1)
                );
            }
        }
    }

    sort(res.begin(), res.end());

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << ' ';
    }

    return 0;
}