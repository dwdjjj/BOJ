#include <queue>
#include <iostream>
using namespace std;
int n, m;
string board[103];
int d[103][103] = {-1, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int>> q;
    d[0][0] = 1; // 방문했다는 의미가 아닌 n,m으로 향하는 최소의 칸수를 세기 위해 시작칸부터 카운팅하기 위함
    q.push({0, 0});
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(d[nx][ny] || board[nx][ny] != '1') continue;
            d[nx][ny] = d[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    
    bfs();
    
    cout << d[n-1][m-1];
    
    
    return 0;
}
