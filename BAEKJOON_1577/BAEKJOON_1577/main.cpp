#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
typedef long long ll;
using namespace std;
const int MAX_N = 100+2;
int n, m;
ll cache[MAX_N][MAX_N];
int disable[MAX_N][MAX_N][2];
int dy[2] = {1, 0}, dx[2] = {0, 1};

// 상태공간 정의 : x를 1늘릴지 y를 1늘릴지 선택하여 이동해 n,m까지 도달하는 (최단경로의) 모든 경우의 수 구하기. 공사 중인 다리가 있을 경우
ll f(int y, int x) {
    if(y > n || x > m) return 0; // 벗어나면 실패
    if(y == n && x == m) return 1; // 도착
    
    ll& ret = cache[y][x];
    if(ret != -1) return ret;
    
    ret = 0;
    
    for(int i=0; i<2; i++) {
        if(disable[y][x][i]) continue;
        int nextY = y + dy[i], nextX = x + dx[i];
        if(nextY<=n && nextX <= m) ret += f(nextY, nextX);
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    int k; cin >> k;
    for(int i=0; i<k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d; // a,b 와 c,d는 거리가 항상 1.
        if(a != c) disable[min(a, c)][b][0] = 1;
        if(b != d) disable[a][min(b, d)][1] = 1;
    }
    cout << f(0, 0);
    return 0;
}
