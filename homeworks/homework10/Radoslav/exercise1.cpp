#include <bits/stdc++.h>
using namespace std;

int dRow[] = { 0, -1, 0, 1 };
int dCol[] = { -1, 0, 1, 0 };

bool isValid(vector<vector<bool>>& v, int n, int row, int col, vector<vector<int>>& matrix) {
    if (row < 0 || col < 0 || row >= n || col >= n || matrix[row][col] == 0 || v[row][col])
        return false;

    return true;
}

void DFS(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int row, int col, int n, int& maxRow, int& maxCol,
       int& minRow,int& minCol) {
    visited[row][col] = true;
    maxCol = max(maxCol, col);
    maxRow = max(maxRow, row);
    minRow = min(minRow, row);
    minCol = min(minCol, col);
    for (int i = 0; i < 4; i++) {
        int adjx = row + dRow[i];
        int adjy = col + dCol[i];

        if (isValid(visited, n, adjx, adjy, matrix)) {
            DFS(matrix, visited, adjx, adjy, n, maxRow, maxCol,minRow,minCol);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<long long> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && matrix[i][j] == 1) {
                int maxRow = -100000000, maxCol = -10000000;
                int minRow = 10000000,minCol = 10000000;
                DFS(matrix, visited, i, j, n, maxRow, maxCol,minRow,minCol);
                long long area = (maxRow - minRow + 1) * (maxCol - minCol + 1);
                res.push_back(area);
            }
        }
    }
    
    sort(res.begin(),res.end());
    
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<< ' ';
    }

    return 0;
}
