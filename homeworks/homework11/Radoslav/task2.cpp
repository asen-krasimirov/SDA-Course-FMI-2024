#include <cmath>
#include <cstdio>
#include <climits>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Eli{
    int row,col,time;
    
    Eli(int r, int c, int t):row(r),col(c),time(t){
        
    }
    
    bool operator>(const Eli& other)const{
        return time>other.time;
    }
};

bool isValid(int x,int y,int n,int m){
    if(x<0 || y<0 || x>=n || y>=m){
        return false;
    }
    return true;
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int djikstra(int n,int m, vector<vector<char>>& grid,int startRow,int startCol){
    vector<vector<int>> distances(n,vector<int>(m,INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    priority_queue<Eli,vector<Eli>,greater<Eli>> pq;
    pq.push(Eli(startRow,startCol,0));
    distances[startRow][startCol]=0;
    
    while (!pq.empty()) {
        int row = pq.top().row;
        int col = pq.top().col;
        int time = pq.top().time;
      
        pq.pop();
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col+  dy[i];
            if (!isValid(newRow, newCol,n,m)) {
                return time;
            }
            if (!visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                if (grid[newRow][newCol] == '#') {
                    pq.push(Eli(newRow,newCol,time + 1));
                }
                else {
                    pq.push(Eli(newRow,newCol,time));
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(1001, vector<char>(1000));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    int maxTimeInGeneral=0;
    int currentMaxTime=0;
     vector<vector<int>> escapeTimes(n, vector<int>(m, INT_MAX));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                int time = djikstra(n,m,grid,i,j);
                if(time!=-1){
                    escapeTimes[i][j] = time;
                }
            }
        }
    }

    int maxEscapeTime = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(escapeTimes[i][j] != INT_MAX && escapeTimes[i][j] > maxEscapeTime){
                maxEscapeTime = escapeTimes[i][j];
            }
        }
    }

    int countMaxEscapeTimeCells = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(escapeTimes[i][j] == maxEscapeTime){
                countMaxEscapeTimeCells++;
            }
        }
    }
    cout<<countMaxEscapeTimeCells<<endl;
    return 0;
}
