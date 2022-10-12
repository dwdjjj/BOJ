#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int T, n, x, y, end_x, end_y, cnt;
vector<vector<int>> adj;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};
void bfs(int x, int y){
    
    pair<int, int> cur;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (x==end_x && y==end_y) {
            return;
        }
        for (int i=0; i<8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if (0<=nx && nx<n && 0<=ny && ny<n) {
                if (!visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    adj[nx][ny] = adj[cur.first][cur.second] + 1;
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> x >> y;
        cin >> end_x >> end_y;
        visited.resize(n, vector<bool>(n, false));
        adj.resize(n, vector<int>(n, 0));
        bfs(x, y);
        cout << adj[end_x][end_y] << "\n";
        visited.clear();
        adj.clear();
    }
    return 0;
}
