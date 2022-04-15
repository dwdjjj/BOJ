#include <vector>
#include <iostream>
using namespace std;
int n, m, cnt = 0, W = 0, B = 0;
bool flag = false;
char adj[101][101];
bool visited[101][101] = {false, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//void dfs(int x, int y, char c) {
//    visited[x][y] = true;
//
//    for (int i=0; i<4; i++) {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//        if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
//        if (!visited[nx][ny] && adj[nx][ny] == c) {
//            cnt++;
//            dfs(nx, ny, c);
//        }
//    }
//}
int dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > m || ny < 0 || ny > n) continue;
            if (adj[nx][ny] == adj[x][y] && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    return cnt;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> adj[i][j];
        }
    }
//    for (int i=0; i<n; i++) {
//        for (int j=0; j<m; j++) {
//            if (!visited[i][j]) {
//                int tmp = 0;
//                tmp = dfs(i, j, 'B');
//                if (adj[i][j] == 'W') {
//                    <#statements#>
//                }
//                B = tmp;
//            }
//
//            cout << B << " ";
//            }
//    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int tmp = 0; cnt = 0;
            if (!visited[i][j]) {
                tmp =  dfs(i, j);
//                cout << tmp << " ";
                if (adj[i][j] == 'W') W += tmp * tmp;
                else B += tmp * tmp;
            }
        }
//        cout << "\n";
    }
//    dfs(0, 0, 'B');
    cout << W << " " << B;
    return 0;
}
