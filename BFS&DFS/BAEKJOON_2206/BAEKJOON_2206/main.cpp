#include <queue>
#include <iostream>
using namespace std;
const int MAX_N = 1000+4;
int n, m;
int adj[MAX_N][MAX_N];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
struct info {
    int y, x;
    bool chance;
};
queue<info> q;
int visited[MAX_N][MAX_N][2] = {0, };

bool is_in_board(int y, int x) {
    if (0<=y && y<n && 0<=x && x<m) return true;
    else return false;
}

int bfs(int y, int x){
    q.push({y, x, true});
    visited[y][x][true] = true;
    
    while (!q.empty()) {
        int curY = q.front().y, curX = q.front().x;;
        bool nowChance = q.front().chance;
        q.pop();
        
        if (curY == n-1 && curX == m-1) return visited[curY][curX][nowChance];
        
        for (int i=0; i<4; i++) {
            int nextY = curY + dy[i], nextX = curX + dx[i];
            if (!is_in_board(nextY, nextX)) continue;
            
            if (nowChance && adj[nextY][nextX] == 1) { // 1은 벽을 의미
                bool nextChance = false;
                if (!visited[nextY][nextX][nextChance]) {
                    visited[nextY][nextX][nextChance] = visited[curY][curX][nowChance] + 1;
                    q.push({nextY, nextX, nextChance});
                }
            }
            if (adj[nextY][nextX] != 1) {
                bool nextChance = nowChance;
                if (!visited[nextY][nextX][nextChance]) {
                    visited[nextY][nextX][nextChance] = visited[curY][curX][nowChance] + 1;
                    q.push({nextY, nextX, nextChance});
                }
            }
        }
    }
    
    return -1;
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &adj[i][j]);
        }
    }

//    cin.ignore();
//    for (int i=0; i<n; i++) {
//        string s;
//        getline(cin, s);
//    }
    cout << bfs(0, 0);
    return 0;
}
