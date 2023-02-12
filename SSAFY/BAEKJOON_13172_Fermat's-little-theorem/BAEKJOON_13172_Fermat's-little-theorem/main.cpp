//
//  main.cpp
//  BAEKJOON_13172_Fermat's-little-theorem
//
//  Created by 권영재 on 2023/02/01.
//

#include <iostream>
typedef long long ll;
const ll mod = 1e9 + 7;
using namespace std;
ll m, a, b, ans = 0;


ll pow(ll x, ll n) {
    ll ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % mod;
        n >>= 1;
        x = x * x % mod;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> m;
    while(m--) {
        cin >> b >> a;
        
        ans += a * pow(b, mod - 2) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}
