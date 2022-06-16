//  BAEKJOON_10986 나머지 합
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long ll;
const int MAX_M = 1000+3;
using namespace std;
ll v[1000000+3];
int n, m;
ll tmp = 0, ans = 0;
ll cnt[MAX_M];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    cnt[0]++; // n개의 수 누적합에 포함되지 않는 0번index의 초기값 0 설정.
    for (int i=1; i<=n; i++) {
        ll x; cin >> x;
        tmp += x;
        v[i] = tmp % m; // 누적합값을 m으로 나눈 나머지 저장
        cnt[v[i]]++;
//        cout << v[i] << " ";
    }
    for (int i=0; i<m; i++) {
//        cout << cnt[i] << " ";
        ans += (cnt[i] * (cnt[i] - 1)) / (2 * 1); // cnt개수 중 두개 선택(조합)
    }
    cout << ans;
    return 0;
}
