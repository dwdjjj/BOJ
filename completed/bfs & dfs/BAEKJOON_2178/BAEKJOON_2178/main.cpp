#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int n, m, cnt = 0;
vector<vector<int>> adj;
vector<vector<int>> d;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(){
    queue<pair<int, int>> q;
    d.resize(n, vector<int>(m, 0));
    q.push({0, 0});
    d[0][0] = 1;
    pair<int, int> cur;
    int nx, ny;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for (int i =0; i < 4; i++) {
            nx = cur.first + dx[i]; ny = cur.second + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(d[nx][ny]==0 && adj[nx][ny]==1){
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
    cin >> n >> m;
    adj.resize(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            if(s[j] == '1')
                adj[i][j] = 1;
        }
    }
    bfs();
    cout << d[n-1][m-1];
    return 0;
}
