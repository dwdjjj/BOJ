#include <algorithm>
#include <string.h>
#include <vector>
#include <cstring>
#include <iostream>
#define INF 987654321
using namespace std;
const int MAX_N = 1000 + 4;
int cache[MAX_N];
int n, ans = 0;
vector<int> v;
// 상태공간 : idx번째에 Vi이하만큼 오른쪽으로 한번에 점프 가능. 맨우측으로 최소한 점프하여 갈 수 있는 방법의 수
int f(int idx) {
    if (idx == n-1) {
        return 0;
    }
    if (n <= idx) {
        return INF;
    }
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    ret = INF; // -1로 초기화 돼있어서 min돌리면 항상 -1이 최솟값으로 나옴 => INF로 초기화
    for (int i=1; i<= v[idx]; i++) {
        ret = min(ret, f(idx+i) + 1);
    }
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    ans = f(0);
    if (ans == INF) {
        cout << -1;
    }
    else cout << ans;
    return 0;
}
