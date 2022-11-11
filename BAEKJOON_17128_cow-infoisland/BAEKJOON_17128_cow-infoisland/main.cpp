#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n, q;
ll ans;
vector<int> v;
vector<int> sum;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    v.resize(n);
    sum.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    for(int i=0; i<n; i++) {
        sum[i] += v[i%n] * v[(i+1)%n] * v[(i+2)%n] * v[(i+3)%n];
        ans += sum[i];
    }
    
    for(int i=0; i<q; i++) {
        int x; cin >> x;
        x--;
        for(int j=0; j<4; j++) {
            int idx = (x - j + n) % n;
            sum[idx] *= -1;
            ans += sum[idx] + sum[idx];
        }
        cout << ans << "\n";
    }
    
    
    return 0;
}
