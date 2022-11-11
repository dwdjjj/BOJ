#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 15+2;
int n;
vector<pair<int, int>> v;
int cache[MAX_N];

// idx일에 상담을 받으면 t일만큼 걸리고 p만큼의 금액을 얻음. 이때, idx+t가 n일을 오바하면 안댐.
// 받지 않는다면 다음날의 상담에 대해 상담을 받을지 말지 정함. 이 방식으로 상담을 통해 얻을 수 있는
// 금액의 최댓값.
int f(int idx) {
    if(idx >= n) return 0;
    
    int& ret = cache[idx];
    if(ret != -1) return ret;
    
    if(idx + v[idx].first > n) return f(idx+1);
    
    return ret = max(f(idx + v[idx].first) + v[idx].second, f(idx + 1));
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i=0; i<n; i++) {
        int t, p; cin >> t >> p;
        v.push_back({t, p});
    }
    cout << f(0);
    return 0;
}
