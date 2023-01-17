#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, idx = 0, ans = 0;
vector<int> v;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
        if(x < 0) idx++;
    }
    
    sort(v.begin(), v.end());
    
    for(int i=n-1; i>=idx; i-=m) {
        ans += v[i]*2;
//        cout << ans << "\n";
    }
    
    for(int i=0; i<idx; i+=m) {
        ans += abs(v[i]*2);
    }
    
//    cout << ans << "\n";
    
    ans -= max(abs(v[0]), abs(v[n-1]));
    // -1 / 3 4 5 6 11
    
    cout << ans;
    
    return 0;
}
