#include <iostream>
using namespace std;
typedef long long ll;
const int MAX_N = 100000+3;
const ll INF = 1e18;
ll crosswalk[MAX_N], arrL[MAX_N], arrR[MAX_N];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> crosswalk[i];
    }
    for(int i=2; i<=n; i++) {
        int x; cin >> x;
        arrL[i] = arrL[i-1] + x;
    }
    for(int i=2; i<=n; i++) {
        int x; cin >> x;
        arrR[i] = arrR[i-1] + x;
    }
    ll ans = INF; int idx = 0;
    for(int i=1; i<=n; i++) {
        ll tmp = crosswalk[i] + arrL[i] + arrR[n] - arrR[i];
        if(tmp < ans) {
            ans = tmp;
            idx = i;
        }
    }
    cout << idx << " " << ans;
    return 0;
}
