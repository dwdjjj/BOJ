#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#define MAX_N 20000+3
#define MAX_M 1000+3
typedef long long ll;
const ll INF = 987654321987654321;
using namespace std;
int N, M, k;
ll cache[MAX_N];
//ll Orange[MAX_N];
vector<ll> Orange;
// 상태공간 : idx번째의 오렌지를 박스에 연속해서 담을지 말지 선택하여 상자엔 최대 M개 넣을 수 있도록 포장하는 비용의 최솟값 구하기.
// k + 오렌지개수(가장 큰 오렌지 - 가장 작은 오렌지) : 박스당 비용 구하는 식
ll f(int idx) {
    if (idx > N) { // 모든 오렌지 넣으면
        return 0;
    }
    
    ll& ret = cache[idx];
    if (ret != -1) return ret;
    
    ret = INF;
    ll Big = Orange[idx], Small = Orange[idx];
    
    for (int i=1; i<=M; i++) { // idx부터 i개만큼 오렌지를 연속으로 상자에 넣고 그 비용구하기
        if (idx + i-1 <= N) {
            Big = max(Big, Orange[idx + i-1]);
            Small = min(Small, Orange[idx + i-1]);
            ret = min(ret, f(idx + i) + k + i * (Big-Small));
        }
    }
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    Orange.resize(N+M+1);
    cin >> N >> M >> k;
    for (int i=1; i<=N; i++) {
        cin >> Orange[i];
    }
    cout << f(1);
    return 0;
}
