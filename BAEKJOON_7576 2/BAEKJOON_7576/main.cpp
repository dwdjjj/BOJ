#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int n, m, maxDay = 0;
queue<pair<int, int>> q;
vector<vector<int>> adj;
//vector<vector<int>> day;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(){
    pair<int, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && adj[nx][ny]!= -1){
                if (adj[nx][ny]==0 || adj[nx][ny] > adj[cur.first][cur.second] + 1) {
                    q.push({nx, ny});
                    adj[nx][ny] = adj[cur.first][cur.second] + 1;
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    //adj.resize(n, vector<int>(m, 0));
    
    for (int i=0; i<n; i++) {
        vector<int> a;
        for (int j=0; j<m; j++){
            int b; cin >> b;
            a.push_back(b);
        }
        adj.push_back(a);
    }
    
    for(int i=0; i<adj.size(); i++){
        for (int j=0; j<adj[i].size(); j++) {
            if (adj[i][j]==1) q.push({i, j});
        }
    }
    bfs();
    
    for (int i=0; i<adj.size(); i++) {
        for (int j=0; j<adj[i].size(); j++) {
            if (adj[i][j] > maxDay) {
                maxDay = adj[i][j];
            }
            if (adj[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    if (maxDay == 1) cout << 0;
    else cout << maxDay - 1;
    
    return 0;
}

/*for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
        cin >> adj[i][j];
        if (adj[i][j] == 1) q.push({i, j});
    }
}*/
/*bool flag = false;
for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
        if (adj[i][j] == 0) {
            flag = false;
            break;
        }
    }
    if (flag == false) break;
}

if (flag) cout << day - 1;
else cout << -1;*/
