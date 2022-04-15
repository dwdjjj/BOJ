#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 50;
int t, m, n, k;
int adj[MAX][MAX] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<int>> v;
vector<vector<bool>> vis;
void bfs() {
    queue<pair<int, int>>q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (!vis[nx][ny] && adj[nx][ny] == 1) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    while (t--) {
        cin >> m >> n >> k;
        v.resize(m, vector<int>(n, 0));
        for (int i=0; i<k; i++) {
            int x, y; cin >> x >> y;
            v[x][y] = 1;
        }
    }
    return 0;
}
