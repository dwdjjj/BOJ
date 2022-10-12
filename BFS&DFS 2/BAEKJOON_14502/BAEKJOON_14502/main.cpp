// 연구소
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int MAX_N = 10;
int n, m, ans = 0;
int arr[MAX_N][MAX_N];
int adj[MAX_N][MAX_N];
//bool visited[MAX_N][MAX_N] = {false, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_in_board(int y, int x) {
    if (0 <= y && y < n && 0 <= x && x < m) return true;
    else return false;
}

void init() { // adj에 입력받은거 arr로 넣어두기
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            arr[i][j] = adj[i][j];
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    init();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 2) { // 바이러스만 bfs 돌리기
                q.push({i, j});
//                visited[i][j] = true;
            }
        }
    }
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int curY = cur.first, curX = cur.second;
        q.pop();
        for (int i=0; i<4; i++) {
            int nextY = curY + dy[i], nextX = curX + dx[i];
            if (!is_in_board(nextY, nextX)) continue;
            if (arr[nextY][nextX] == 0 ) {
//                visited[nextY][nextX] = true;
                arr[nextY][nextX] = 2;
                q.push({nextY, nextX});
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) { // 0인 영역 세기
        for (int j=0; j<m; j++) {
            if(arr[i][j] == 0) cnt++;
        }
    }
    
    ans = max(cnt, ans);
}
void wall(int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (adj[i][j] == 0) {
                adj[i][j] = 1;
                wall(cnt+1);
                adj[i][j] = 0;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (adj[i][j] == 0) {
                adj[i][j] = 1;
                wall(1);
                adj[i][j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
