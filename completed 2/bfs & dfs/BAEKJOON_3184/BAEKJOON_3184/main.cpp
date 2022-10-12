#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int R, C, num_o = 0, num_v = 0;
vector<vector<char>> adj;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    pair<int, int> cur;
    int nx, ny;
    int cnt_o = 0, cnt_v = 0;
    
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(adj[cur.first][cur.second] == 'o') cnt_o++;
        else if(adj[cur.first][cur.second] == 'v') cnt_v++;
        
        for(int i=0; i<4; i++){
            nx = cur.first + dx[i]; ny = cur.second + dy[i];
            if(0<=nx && nx<R && 0<=ny && ny<C){
                if(!visited[nx][ny] && adj[nx][ny]!='#'){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    if(cnt_o > cnt_v) num_o += cnt_o;
    else num_v += cnt_v;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> R >> C;
    adj.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> adj[i][j];
        }
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(!visited[i][j] && (adj[i][j] == 'v' || adj[i][j] == 'o')) bfs(i, j);
        }
    }
    cout << num_o << " " << num_v;
    return 0;
}
