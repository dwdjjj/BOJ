#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#define MAX_N 50+3
using namespace std;
int r, c, ans = 0;
int d[MAX_N][MAX_N];
vector<vector<char>> adj;
bool visited[MAX_N][MAX_N] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_in_board(int y, int x) {
    if (0 <= y && y < r && 0 <= x && x < c) {
        return true;
    }
    else return false;
}

// y,x에서부터 이어진 땅중에 가장 멀리있는 땅까지의 거리 구하기
int bfs(int y, int x) {
    memset(d, 0, sizeof(d));
    queue<pair<int, int>> q;
    int res = 0;
    
    q.push({y, x});
    d[y][x] = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int curY = cur.first, curX = cur.second;
        q.pop();
        for (int i=0; i<4; i++) {
            int nextY = curY + dy[i], nextX = curX + dx[i];
            
            res = max(res, d[curY][curX]);
            if(!is_in_board(nextY, nextX)) continue;
            if (!d[nextY][nextX] && adj[nextY][nextX] == 'L') {
                d[nextY][nextX] = d[curY][curX] + 1;
                q.push({nextY, nextX});
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(d, 0, sizeof(d));
    cin >> r >> c;
    adj.resize(r, vector<char>(c));
    
    // 입력부분에서 계속틀렸었는데, scanf로 "%1s"나 "%1c"로 입력받는 경우 틀렸다고 뜸
    // 우선 가장 베스트는 string adj[n]혹은 char adj[n][n]으로 선언한 후
    // 이중for문이 아닌 단일 for문만 r번돌리면서 한 문장씩 입력받거나 vector로 선언해서 resize로 크기지정만 해주면 평소처럼 cin으로 입력받아도 됨.
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> adj[i][j];
        }
    }
    
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (adj[i][j] == 'L') {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans-1;
    
    
    return 0;
}
