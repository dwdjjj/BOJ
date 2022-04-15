#include <iostream>
typedef long long ll;
using namespace std;
int t;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        ll ans;
        ll n; cin >> n;
        ll cnt = 10;
        while (cnt <= n) {
            cnt = cnt * 10;
        }
        ll tmp = min(cnt/2 - 1, n);
        ans = tmp * (cnt - tmp - 1);
        cout << ans << '\n';
    }
    return 0;
}
