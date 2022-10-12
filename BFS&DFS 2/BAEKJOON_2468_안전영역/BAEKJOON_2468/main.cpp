#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
//vector<vector<int>> adj;
//vector<vector<bool>> vis;
bool vis[103][103] = {false, };
int adj[103][103];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int h){
    vis[x][y] = 1;
//        pair<int, int> cur = s.top();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(adj[nx][ny] <= h || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            dfs(nx, ny, h);
        }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int m = 103, M = 0;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++) {
            cin >> adj[i][j];
            m = min(adj[i][j], m);
            M = max(adj[i][j], M);
        }
    }
    
    int res = 1;
    for(int i=m; i<=M; i++){
        int cnt = 0;
        memset(vis, false, sizeof(vis));
        
        for(int j=0; j<n; j++){
            for (int k=0; k<n; k++) {
                if(!vis[j][k] && adj[j][k] > i){
                    vis[j][k] = true;
                    cnt++;
                    dfs(j, k, i);
                }
                    
            }
        }
        res = max(cnt, res);
    }
    cout << res;
    
    return 0;
}
