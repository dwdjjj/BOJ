#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX_N = 1000 + 4;
int p, n, h;
vector<int> v[104];
int cache[MAX_N][25];
// 상태공간 : idx번째에서 해당pc에서 희망시간만큼 영업 할지 말지 정하여 총 h시간만큼 운영하여
// 각 pc당 얻을 수 있는 최대 수익 구하기
int f(int idx, int sum, int PC) {
    if (idx == v[PC].size()) {
        return 0;
    }
    
    int& ret = cache[idx][sum];
    if (ret != -1) return ret;
    
    ret = f(idx+1, sum, PC);
    if (sum + v[PC][idx] <= h) {
        ret = max(ret, f(idx+1, sum + v[PC][idx], PC) + v[PC][idx]);
    }
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> p >> n >> h;
    for (int i=0; i<n; i++) {
        int x; ll y;
        cin >> x >> y;
        if (y <= h) {
            v[x].push_back(y);
        }
    }
    for (int i=1; i<= p; i++) {
        memset(cache, -1, sizeof(cache));
        cout << i << " " << f(0, 0, i) * 1000 << "\n";
    }
    return 0;
}
//2 7 4
//1 10
//1 5
//1 7
//2 10
//2 1
//2 3
//2 7
