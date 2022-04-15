#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100;
int m, n, k;
int adj[MAX][MAX] = {0, };
bool vis[MAX][MAX] = {false, };
vector<int> res;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    int cnt = 0;
    while (!q.empty()) {
        pair<int, int>cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (adj[x][y] == 0) cnt++;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <0 || ny <0 || nx >= m || ny >= n) continue;
            if (!vis[nx][ny] && adj[nx][ny] == 0) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    return cnt;
}
void f(int sx, int sy, int ex, int ey) {
    for (int i=sx; i<ex; i++) {
        for (int j=sy; j<ey; j++) {
            adj[j][i] = 1;
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> m >> n >> k;

    for (int i=0; i<k; i++) {
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;
        f(startX, startY, endX, endY);
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (adj[i][j] == 0 && !vis[i][j]) {
                int tmp = bfs(i, j);
                res.push_back(tmp);
            }
        }
    }
    sort(res.begin(), res.end());
    
    cout << res.size() << "\n";
    
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    
//    for (int i=0; i<m; i++) {
//        for (int j=0; j<n; j++) {
//            cout << adj[i][j];
//        }
//        cout << "\n";
//    }
    return 0;
}
