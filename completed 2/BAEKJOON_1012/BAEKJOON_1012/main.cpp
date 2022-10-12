#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
//vector<vector<int>>adj[53];
int adj[52][52];
bool vis[52][52];
// vector<bool>visited;
int T, m, n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    vis[y][x] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if(!vis[ny][nx] && adj[ny][nx]){
            vis[y][x] = true;
            dfs(ny, nx);
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> T;
    while(T--){
        cin >> m >> n >> k;
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));
        
        while(k--){
            int x, y;
            cin >> x >> y;
            adj[y][x] = 1;
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(adj[i][j] && !vis[i][j]){
                    dfs(i, j);
                    vis[i][j]=true;
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
