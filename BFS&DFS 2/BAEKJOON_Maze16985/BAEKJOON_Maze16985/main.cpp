#include <queue>
#include <iostream>
using namespace std;
const int MAX_N = 5+3;
const int INF = 987654321;
int board[MAX_N][MAX_N][MAX_N], tmp[MAX_N][MAX_N][MAX_N];
int visited[MAX_N][MAX_N][MAX_N] = {-1, };
bool selected[MAX_N] = {0, };
int ans = INF;
struct info {
    int z, y, x;
};
int dxyz[6][3] = {
    {1, 0, 0}, {0, 1, 0}, {-1, 0, 0}, {0, -1, 0},
    {0, 0, 1}, {0, 0, -1}
};
void rotation(int z) { // 방향돌리기
    int res[MAX_N][MAX_N] = {0, };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res[i][j] = board[z][5-1-j][i];
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            board[z][i][j] = res[i][j];
        }
    }
}
void select(int z, int idx) { // z층 판을 idx층 판으로 선택
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            board[z][i][j] = tmp[idx][i][j];
        }
    }
}
bool is_in_board(int y, int x, int z) {
    if (y < 5 && y >= 0 && x < 5 && x >= 0 && z < 5 && z >= 0) return true;
    else return false;
}

int bfs() {
    memset(visited, -1, sizeof(visited));
    queue<info> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 0;
    
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        
        for (int i=0; i<6; i++) {
            int nextY = cur.y + dxyz[i][0];
            int nextX = cur.x + dxyz[i][1];
            int nextZ = cur.z + dxyz[i][2];
            
            if (!is_in_board(nextY, nextX, nextZ)) continue;
            if (board[nextZ][nextY][nextX] == 1 && visited[nextZ][nextY][nextX] == -1) {
                visited[nextZ][nextY][nextX] = visited[cur.z][cur.y][cur.x] + 1;
                q.push({nextZ, nextY, nextX});
            }
//            cout << visited[nextZ][nextY][nextX] << " ";
        }
        
    }
    return visited[4][4][4];
}
void dfs(int z) {
    if (z > 4) {
        if (board[0][0][0] == 1) {
            int cnt = bfs();
            if (cnt != -1) ans = min(ans, cnt);
        }
        return;
    }
    
    for (int i=0; i<5; i++) {
        if (!selected[i]) {
            selected[i] = true;
            select(z, i);
            
            for (int j=0; j<4; j++) {
                rotation(z);
                dfs(z+1);
            }
            selected[i] = false;
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int z=0; z<5; z++) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                cin >> tmp[z][i][j];
            }
        }
    }

    dfs(0);
    
    if (ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
