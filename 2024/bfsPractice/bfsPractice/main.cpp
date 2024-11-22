#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, m;
vector<vector<int>> board;
vector<vector<int>> ans;

bool isInBoard(int y, int x) {
     return 0 <= y && 0 <= x && y < n && x < m;
 }

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    ans[y][x] = 0;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        int curY = cur.first;
        int curX = cur.second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            
            if(!isInBoard(nextY, nextX) || ans[nextY][nextX] >= 0) continue;
            if(board[nextY][nextX] == 0) continue;
            ans[nextY][nextX] = ans[curY][curX] + 1;
            q.push({nextY, nextX});
        }
    }

    return;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    ans.resize(n, vector<int>(m, -1));
    board.resize(n, vector<int>(m, 0));
    int y = 0, x = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                y = i; x = j;
            }
        }
    }
    bfs(y, x);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            (board[i][j] == 0) ?
            cout << board[i][j] << " ":
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
