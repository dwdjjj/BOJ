#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define MAX 25+1
using namespace std;
int adj[MAX][MAX];
bool visited[MAX][MAX] = {0, };
//vector<vector<int>> adj;
//vector<vector<bool>> visited;
vector<int> house_cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, cnt = 0;

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    pair<int, int> cur;
    int nx, ny;
    cnt++;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            nx = cur.first + dx[i]; ny = cur.second + dy[i];
            if(0 <= nx && nx<N && 0<= ny && ny < N){
                if(!visited[nx][ny] && adj[nx][ny] == 1){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
        
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    //adj.resize(N, vector<int>(N));
    //visited.resize(N, vector<bool>(N, false));
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<N; j++){
            adj[i][j] = s[j] - '0';
        }
    }
    
    for (int i=0; i<N; i++) {
        for(int j=0; j<N; j++){
            if(adj[i][j]==1 && !visited[i][j]){
                cnt = 0;
                bfs(i, j);
                house_cnt.push_back(cnt);
            }
        }
    }
    cout << house_cnt.size() << "\n";
    sort(house_cnt.begin(), house_cnt.end());
    
    for (int i=0; i < house_cnt.size(); i++) {
        cout << house_cnt[i] << "\n";
    }
    return 0;
}
