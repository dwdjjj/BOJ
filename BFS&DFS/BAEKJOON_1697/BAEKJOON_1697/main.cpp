#include<iostream>
#include <queue>
#define MAX_N 100000+4
using namespace std;
int n, k, ans = 0;
bool visited[MAX_N] = {false, };
int dx[2] = {-1, 1};
void bfs(int x) {
    queue<pair<int, int>> q; // n위치에서 찾을 시간 0입력
    q.push({n, 0});
    while (!q.empty()) {
        int cur = q.front().first, cnt = q.front().second;
        
        if (cur == k) {
            ans = cnt;
            break;
        }
        q.pop();
        for (int i=0; i<2; i++) {
            int next = cur + dx[i];
            if (next < 0 || MAX_N < next) continue;
            if (!visited[next]) {
                q.push({next, cnt+1});
                visited[next] = true;
            }
        }
        int tp = cur * 2;
        if (tp < 0 || MAX_N < tp) continue;
        if (!visited[tp]) {
            visited[tp] = true;
            q.push({tp, cnt+1});
        }
        
    }
}
int main()
{
    cin >> n >> k;
    bfs(n);
    cout << ans;
    return 0;
}
