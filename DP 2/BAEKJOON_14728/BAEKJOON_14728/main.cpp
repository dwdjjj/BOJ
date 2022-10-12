#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 987654321;
int n, t;
vector<pair<int, int>> v;
int cache[100+3][10000+3];

// 상태공간 정의 : idx번째의 과목을 공부할지 말지 선택해서 얻을 수 있는 최대 점수 반환
// 모든단원 다훑엇으면 종료, 더해가다가 time이 총 시간을 오바하면 실패 반환.
int f(int idx, int time) {
    
    if (time < 0) {
        return -INF;
    }
    if (idx >= n) {
        return 0;
    }
    
    int &ret = cache[idx][time];
    if (ret != -1) return ret;
    
    ret = max(f(idx + 1, time - v[idx].first) + v[idx].second, f(idx + 1, time));
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    
    cin >> n >> t;
    
    for (int i=0; i<n; i++) {
        int k, s;               // k : 단원 별 공부 시간, s : 그 단원 문제 배점
        cin >> k >> s;
        v.push_back({k, s});
    }
    cout << f(0, t);
    
    return 0;
}
