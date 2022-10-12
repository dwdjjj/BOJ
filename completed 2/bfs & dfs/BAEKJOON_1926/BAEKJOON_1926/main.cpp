#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[503][503];
bool vis[503][503];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    int num = 0, M = 0;
    
    // 이중 for문으로 각 칸이 BFS의 시작점이 될 수 있는지를 체크해주면 도화지에 있는 모든 그림을 찾아낼 수 있다.
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(arr[i][j] == 0 || vis[i][j]) continue;
            num++;
            queue<pair<int, int>> q;
            vis[i][j] = 1;
            q.push({i, j});
            int cnt = 0;
            while (!q.empty()) {
                cnt++;
                pair<int, int> cur = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue; // 범위밖
                    if(vis[nx][ny] || arr[nx][ny] != 1) continue; // 빨간땅
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            M = max(M, cnt);
        }
    }
    cout << num << "\n" << M;
    
    return 0;
}
