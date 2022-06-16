#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 1000+4;
int r, c, k;
int sr, sc;
bool visited[MAX_N][MAX_N] = {false, };
int d[4];
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};
bool is_in(int y, int x) {
    if (0 <= y && y < r && 0 <= x && x < c) return true;
    else return false;
}
void f(int y, int x, int z) {
    bool flag = true;
    for(int i=0; i<4; i++) {
        int nextY = y + dy[d[z]];
        int nextX = x + dx[d[z]];
        if (is_in(nextY, nextX) && !visited[nextY][nextX]) {
            visited[nextY][nextX] = true;
            f(nextY, nextX, z);
            flag = false;
            break;
        }
        z = (z + 1) % 4;
    }
    
    if (flag) {
        sr = y;
        sc = x;
    }
}
int main(int argc, const char * argv[]) {
    cin >> r >> c >> k;
    while (k--) {
        int br, bc; cin >> br >> bc;
        visited[br][bc] = 1;
    }
    cin >> sr >> sc;
    visited[sr][sc] = 1;
    for (int i=0; i<4; i++) {
        cin >> d[i];
    }
    f(sr, sc, 0);
    
    cout << sr << " " << sc;
    return 0;
}
