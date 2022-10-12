#include <queue>
#include <iostream>
using namespace std;
// 명검을 먹으면 벽을 뚫고 갈 수 있으니 y,x외에 변수로써 추가해준다.
// tip! : 문제에 조건으로 들어가는 변수를 큐에 추가할 것!!
// visited배열과 queue의 구성은 동일해야함!
// 큐에 넣을변수가 세개 이상이 되어 pair를 써도는 되나 struct로 선언해주면 좋다.
const int MAX_N = 100+4, INF = 987654321;
int n, m, t;
int adj[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][2] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct info {
    int y, x;
    bool Sword;
};
queue<info> q;

bool is_in_board(int y, int x) {
    if (0 <= y && y < n && 0 <= x && x < m) return true;
    else return false;
}
// y, x로 진행
int bfs(int y, int x) {
    q.push({y, x, false});
    visited[y][x][false] = true;
    while (!q.empty()) {
        int curY = q.front().y, curX = q.front().x;
        bool nowHave = q.front().Sword;
        q.pop();
        if (curY == n-1 && curX == m-1) return visited[curY][curX][nowHave] - 1;
        for (int i=0; i<4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (!is_in_board(nextY, nextX)) continue;
            bool nextHave = nowHave;
            if (adj[nextY][nextX] == 2) nextHave = true; // 2는 Sword(명검 그람)가 놓인 곳을 의미
            
            if (nextHave && !visited[nextY][nextX][nextHave]) {
                visited[nextY][nextX][nextHave] = visited[curY][curX][nowHave] + 1;
                q.push({nextY, nextX, nextHave});
            }
            
            if (!nextHave && !visited[nextY][nextX][nextHave] && adj[nextY][nextX] != 1) {
                visited[nextY][nextX][nextHave] = visited[curY][curX][nowHave] + 1;
                q.push({nextY, nextX, nextHave});
            }
        }
    }
    return INF;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> adj[i][j];
        }
    }
    int res = bfs(0, 0);
    if (res <= t) cout << res;
    else cout << "Fail";
    return 0;
}
