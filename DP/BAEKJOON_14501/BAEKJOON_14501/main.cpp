#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
int n;
int cache[20];
vector<pair<int, int>> v;
int T[20];
int P[20];
// 상태공간정의 : idx일에 상담을 받을지 말지에 대한 행위로 받을 수 있는 금액의 최대.
// T일만큼 상담이 걸려 ex) 3일걸리는 상담 받으면 다음,그다음날껀 못받음, N을 넘는 날에는 회사에 없어 상담 불가.
int f(int idx) {
    
    if (idx > n) return 0;
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    if (idx + v[idx].first > n+1) return f(idx + 1);
//    if (idx + T[idx] > n+1) return f(idx + 1);
    
    return ret = max(f(idx + v[idx].first) + v[idx].second, f(idx + 1));
//    return ret = max(f(idx + T[idx]) + P[idx], f(idx + 1));

    return ret;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    v.resize(n+1);
    for (int i=1; i<=n; i++) {
        int t, p;
        cin >> t >> p;
        v[i] = {t, p};
//        cin >> T[i] >> P[i];
    }
    cout << f(1);
    return 0;
}
