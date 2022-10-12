#include <vector>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, m;
vector<int> v;
bool is_possible(ll mid) {
    ll sum = 0;
    for (int i=0; i<n; i++) {
        if (mid < v[i]) {
            sum += v[i] - mid;
        }
    }
    if (sum >= m) return true;
    else return false;
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll left = 0, right = 1e9+2, ans = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (is_possible(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
//5 2000000000 900000000 900000000 900000000 900000000 900000000

