#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX_N = 40+3;
int n, m, cnt = 0, last = 0;
ll ans = 1, tmp;
ll cache[MAX_N];
// idx번 좌석배정자들은 idx-1 or idx+1자리에도 앉을 수 있지만, VIP회원의 경우 반드시 자기자리에만 앉아야 한다. VIP회원들의 좌석은 고정시켜둔 상태에서 사람들이 좌석에 앉을 수 있는 방법의 수 구하기.
// vip가
// 1자리면 1
// 2자리면 2가지
// 3자리면 3가지
// 4자리면 1234 1243 2134 2143 1324 => 5가지
// 5자리면 12345 12354 12435 13245 13254 21345 21354 21435 => 8가지
// 자리방법수가 피보나치 규칙으로 늘어남
ll f(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    
    ll& ret = cache[n];
    if (ret != -1) return ret;
    
    return ret = f(n-1) + f(n-2);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    for (int i=0; i<m; i++) { // x번 좌석은 vip회원임
        int x; cin >> x;
        tmp = f(x - last - 1);
        if(0 < tmp) ans *= tmp;
        last = x;
    }
    tmp = f(n - last);
    if (0 < tmp) {
        ans *= tmp;
    }
    cout << ans;
    return 0;
}
