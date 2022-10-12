#include <queue>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
int row, col, ans;
//vector<vector<int>> adj;
int adj[1004][1004];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool is_in_board(int y, int x){
    if (0 <= y && 0 <= x && y < row && x < col) return true;
    else return false;
}

void bfs() {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int curY = cur.first;
        int curX = cur.second;
        q.pop();
        for (int i=0; i<4; i++){
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (is_in_board(nextY, nextX) && adj[nextY][nextX] != -1) {
                if (adj[nextY][nextX] == 0 || adj[nextY][nextX] > adj[curY][curX] + 1) {
                    q.push({nextY, nextX});
                    adj[nextY][nextX] = adj[curY][curX] + 1;
                }
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(adj, 0, sizeof(adj));
    cin >> col >> row;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (adj[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    bfs();
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (adj[i][j] > ans) {
                ans = adj[i][j];
            }
            if (adj[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
//    for (int i=0; i<row; i++) {
//        for (int j=0; j<col; j++) {
//            cout << adj [i][j] << " ";
//        }
//        cout << "\n";
//    }
    if (ans == 1) cout << 0;
    else cout << ans - 1;
    
    return 0;
}
