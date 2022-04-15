#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int n, m;
vector<string> adj;
vector<vector<int>> vis;
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs() {
    q.push({0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        pair<int, int>cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (!vis[nx][ny] && adj[nx][ny] == '1') {
                vis[nx][ny] += vis[x][y] + 1;
                q.push({nx, ny});
            }
        }
//        cout << vis[x][y] << "\n";
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    vis.resize(n, vector<int>(m, 0));
    adj.resize(n, "");
    for (int i=0; i<n; i++) {
        cin >> adj[i];
    }
    bfs();
    cout << vis[n-1][m-1];
    return 0;
}
