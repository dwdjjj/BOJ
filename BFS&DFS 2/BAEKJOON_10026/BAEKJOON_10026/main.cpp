#include <queue>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
const int MAX_N = 100+4;
string arr[MAX_N];
int visited[MAX_N][MAX_N] = {0, };
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int N, cnt = 0;
bool is_in_board(int y, int x) {
    if (0 <= y && y<N && 0<=x && x<N) return true;
    else return false;
}
void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        int nowY = cur.first, nowX = cur.second;
        q.pop();
        for (int i=0; i<4; i++) {
            int nextY = nowY + dy[i], nextX = nowX + dx[i];
            if (!is_in_board(nextY, nextX)) continue;
            if (!visited[nextY][nextX]) {
                if (arr[nextY][nextX] == arr[nowY][nowX]) {
                    visited[nextY][nextX] = true;
                    q.push({nextY, nextX});
                }
            }
            
        }
    }
}
//void dfs(int y, int x) {
//    for (int i=y; i< N; i++) {
//        for (int j = x; j<N; j++) {
//            if (visited[i][j]) {
//                return 0;
//            }
//            visited[i][j]++;
//            if (arr[i][j] == ) {
//                <#statements#>
//            }
//        }
//    }
//}
int main(int argc, const char * argv[]) {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    memset(visited, false, sizeof(visited));
    cnt = 0;
    for (int i=0; i<N; i++) { // 다 초록으로
        for (int j=0; j<N; j++) {
            if (arr[i][j] == 'R') {
                arr[i][j] = 'G';
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
