#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int INF = 987654321;
int r, c, ans = -INF;
char adj[23][23];
int dy[4] = {0, 1, -1, 0}, dx[4] = {1, 0, 0, -1};
bool visited[23][23] = {false, };
bool visA[26] = {false, };

bool is_in_board(int y, int x) {
    if (y >= 0 && y < r && x >= 0 && x < c) return true;
    else return false;
}

void dfs(int y, int x, int cnt) {
    visA[adj[y][x] - 'A'] = true;
    if (cnt > ans) ans = cnt;
    for (int i=0; i<4; i++) {
        int nextY = y + dy[i], nextX = x + dx[i];
        if (!is_in_board(nextY, nextX)) continue;
        if (!visA[adj[nextY][nextX] - 'A']) {
            
            dfs(nextY, nextX, cnt + 1);
            visA[adj[nextY][nextX] - 'A'] = false;
        }
    }
    
}
// bfs로 풀면 안댐.
//int bfs() {
//    int cnt = 0;
//    visited[0][0] = true;
//    queue<pair<int, int>>q;
//    pair<int, int> cur;
//    cur = q.front();
//    while (!q.empty()) {
//        q.pop();
//        int nowY = cur.first, nowX = cur.second;
//        for (int i=0; i<4; i++) {
//            int nextY = nowY + dy[i], nextX = nowX + dx[i];
//            if (!is_in_board(nextY, nextX)) continue;
//            if (!visited[nextY][nextX] && !visA[adj[nextY][nextX] - 'A']) {
//                visited[nextY][nextX] = true;
//                visA[adj[nextY][nextX] - 'A'] = true;
//                q.push({nextY, nextX});
//                cnt++;
//            }
//        }
//    }
//    return cnt;
//}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(visA, false, sizeof(visA));
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> adj[i][j];
        }
    }
    
    dfs(0, 0, 1);
    cout << ans;
//    cout << bfs();
    return 0;
}
