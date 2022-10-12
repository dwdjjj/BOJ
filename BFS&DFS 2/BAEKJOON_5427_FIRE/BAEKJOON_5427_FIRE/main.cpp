#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int MAX_N = 1000+4;
int t, w, h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[MAX_N][MAX_N] = {0, };
char adj[MAX_N][MAX_N];
queue<pair<int, int>>q;
bool is_in_board(int y, int x) {
    if (0<=y && y<h && 0<=x && x<w) return true;
    else return false;
}
void bfs() {
    pair<int, int> cur = q.front();
    while (!q.empty()) {
        int curY = cur.first, curX = cur.second;
        q.pop();
        for (int i=0; i<4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (!is_in_board(nextY, nextX)) continue;
            if (adj[nextY][nextX] != '#' && !visited[nextY][nextX]) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = visited[nextY][nextX] + 1;
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        cin >> w >> h;
        memset(visited, false, sizeof(visited));
        memset(adj, 0, sizeof(adj));
        cin.ignore();
        for (int i=0; i<h; i++) {
            string s;
            getline(cin, s);
            for (int j=0; j<w; j++) {
                adj[i][j] = s[j];
            }
        }
    }
    return 0;
}
