#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 100+2;
int n, m, h, ans;
int arr[MAX_N][MAX_N][MAX_N];
int res[MAX_N][MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N];
//int d[6][6][6] = {
//    {1,0,0}, {0,1,0}, {-1,0,0}, {0,-1,0}, {0,0,1}, {0,0,-1}
//};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct box {
    int y, x, z;
};
bool is_in_board(int y, int x, int z) {
    if(y < 0 || y >= n || x < 0 || x >= m || z < 0 || z >= h) return false;
    else return true;
}

queue<box> q;

void bfs() {
    while(!q.empty()) {
        int curY = q.front().y, curX = q.front().x, curZ = q.front().z;
        q.pop();
        
        for(int i=0; i<6; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            int nextZ = curZ + dz[i];
            if(!is_in_board(nextY, nextX, nextZ)) continue;
            if(arr[nextY][nextX][nextZ] == -1) continue;
            if(arr[nextY][nextX][nextZ] == 0 || arr[nextY][nextX][nextZ] == arr[curY][curX][curZ]+1) {
                q.push({nextY, nextX, nextZ});
                arr[nextY][nextX][nextZ] = arr[curY][curX][curZ]+1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> h;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<h; k++) {
                cin >> arr[i][j][k];
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<h; k++) {
                if(arr[i][j][k]) q.push({i, j, k});
            }
        }
    }
    bfs();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<h; k++) {
                if(arr[i][j][k] > ans) ans = arr[i][j][k];
                cout << arr[i][j][k] << " ";
                if(!arr[i][j][k]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << ans;
    
    
    return 0;
}
