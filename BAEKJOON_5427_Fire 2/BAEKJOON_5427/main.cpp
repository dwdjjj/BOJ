#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
vector<vector<char>> adj;
vector<vector<int>> d;
int n, h, w, ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int x, int y){
    queue<pair<int, int>>q;
    d.resize(h, vector<int>(w,0));
    q.push({0, 0});
    d[0][0] = 1;
    pair<int, int> cur;
    int nx, ny;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            nx = cur.first + dx[i]; ny = cur.second + dy[i];
            if(nx>=0 && nx<h && ny>=0 && ny<w){
                if(d[nx][ny]==0 && adj[nx][ny]!='#'){
                    q.push({nx, ny});
                    d[nx][ny] = d[cur.first][cur.second] + 1;
                }
            }
        }

    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> w >> h;
    
    while(n--){
        int max = 0;
        adj.resize(h, vector<char>(w));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> adj[i][j];
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(adj[i][j]=='@') bfs(i, j);
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(d[i][j] > max) max = adj[i][j];
            }
        }
        cout << max << '\n';
    }
    
    return 0;
}
