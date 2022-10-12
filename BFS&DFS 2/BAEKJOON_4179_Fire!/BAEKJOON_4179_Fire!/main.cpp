#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int MAX_N = 1000+4;
const int INF = 987654321;
int R, C;
string adj[MAX_N];
//char adj[MAX_N][MAX_N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vF[MAX_N][MAX_N];
int vJ[MAX_N][MAX_N];
queue<pair<int, int>> qF;
queue<pair<int, int>> qJ;
bool is_in_board(int y, int x) {
    if (0<= y && y < R && 0<= x && x < C) return true;
    else return false;
}
void bfsFire() {
    while(!qF.empty()) {
        pair<int, int> cur = qF.front();
        int nowY = cur.first, nowX = cur.second;
        qF.pop();
        for (int i=0; i<4; i++) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if (!is_in_board(nextY, nextX)) continue;
            if (adj[nextY][nextX] == '#' || vF[nextY][nextX]) continue;
            vF[nextY][nextX] = vF[nowY][nowX] + 1;
            qF.push({nextY, nextX});
        }
    }
}
void bfsJ() {
    int ans = INF;
    while (!qJ.empty()) {
        pair<int, int> cur = qJ.front();
        int nowY = cur.first, nowX = cur.second;
        qJ.pop();
        for (int i=0; i<4; i++) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if (!is_in_board(nextY, nextX)) {
                ans = min(ans, vJ[nowY][nowX]);
                continue;
            }
            if (adj[nextY][nextX] == '#' || vJ[nextY][nextX]) continue;
            if (vF[nextY][nextX] && vF[nextY][nextX] <= 1 + vJ[nowY][nowX]) continue;
            vJ[nextY][nextX] = vJ[nowY][nowX] + 1;
            qJ.push({nextY, nextX});
        }
    }
    if (ans == INF) cout << "IMPOSSIBLE";
    else cout << ans;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0; i<R; i++) {
        memset(vF[i], 0, sizeof(vF[i]));
    }
    for (int i=0; i<R; i++) {
        memset(vJ[i], 0, sizeof(vJ[i]));
    }
//    memset(vF, 0, sizeof(vF));
//    memset(vJ, 0, sizeof(vJ));
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        cin >> adj[i];
    }
//    for (int i=0; i<R; i++) {
//        for (int j=0; j<C; j++) {
//            cin >> adj[i][j];
//        }
//    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (adj[i][j] == 'F') {
                qF.push({i, j});
                vF[i][j] = 1;
            }
            else if (adj[i][j] == 'J') {
                qJ.push({i, j});
                vJ[i][j] = 1;
            }
        }
    }
    bfsFire();
    bfsJ();
//    for (int i=0; i<R; i++) {
//        for (int j=0; j<C; j++) {
//            cout << vF[i][j];
//        }
//        cout << "\n";
//    }
    return 0;
}
//4 4
//####
//#JF#
//#..#
//#..#
//
//4 4
//####
//JF.#
//#..#
//#..#
