#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX_N 10000 + 4
#define MAX_M 500 + 3
#define INF 987654321
using namespace std;
int n, m;
int cache[MAX_N][MAX_M];
vector<int> v;
// idx번째에 달릴지 말지 정하고, 지침지수는 m을 넘지 않는 선에서 달려야하고, 달리기가 끝날 때 지침지수는 0이되어야 하는 갈 수 있는 최대거리
int f(int idx, int cnt) {
    if (idx == n+1) {
        if (cnt == 0) return 0;
        if (cnt != 0) return -INF;
    }
    if (idx > n+1) return -INF;
    
    int& ret = cache[idx][cnt];
    if (ret != -1) return ret;
    
    if (cnt == 0) { // 지침지수 0일 때
        return ret = max(f(idx + 1, 0), f(idx + 1, 1) + v[idx]);
    }
    else if (cnt >= m) { // 지침지수가 m이상이면 무조건 m만큼 쉬어주기
        return ret = f(idx + m, 0);
    }
    else return ret = max(f(idx + 1, cnt + 1) + v[idx], f(idx + cnt, 0)); // 지침지수가 0~m사이면 idx번째에 뛰거나 cnt만큼 쌓인 지침지수를 내리는 선택 중 최댓값 반환
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    v.resize(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    cout << f(1, 0);
    return 0;
}
