#include <algorithm>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
const int MAX_N = 100 + 4;
const int INF = 1e9;
int n, s, h, w;
struct info{
    int size, height, weight;
};
vector<info> v;
int cache[MAX_N][MAX_N];
// 벽돌은 무거운게 아래로, 넓이가 넓은게 아래로
// 상태공간 : idx번째 벽돌을 쌓아서 총 몇개의 벽돌을 쌓게 될지, 그리고 그 번호 출력
// last의 무게보다 가볍고 넓이보다 작은지 체크해가며 쌓을 수 있는 가장 높은 높이값 구하기
int f(int idx, int last) {
    if (idx == n) {
        return 0;
    }
    
    int& ret = cache[idx][last];
    if (ret != -1) return ret;
    
    if (v[idx].size < ) {
        <#statements#>
    }
    return ret = max(f(idx+1, ), <#const _Tp &__b#>)
    
}
int main(int argc, const char * argv[]) {
    cin >> n;
    v.resize(n+1);
    for (int i=1; i<=n; i++) {
        cin >> s >> h >> w;
        v.push_back({s, h, w});
    }
    
    return 0;
}
