//
//  main.cpp
//  BAEKJOON_23888
//
//  Created by 권영재 on 2023/01/30.
//

#include <iostream>
typedef long long ll;
using namespace std;
ll a, d, q;

ll gcd (ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> d >> q;
    
    for(int i = 1; i <= q; i++) {
        ll type, l, r;
        cin >> type >> l >> r;
        if(type == 1) {
            ll s1 = r * (2 * a + (r - 1) * d) / 2;
            ll s2 = (l - 1) * (2 * a + (l - 2) * d) / 2;
            cout << s1 - s2 << "\n";
        }
        else {
            if(l==r) cout << a + (l - 1) * d << "\n";
            else cout << gcd(a, d) << "\n";
        }
    }
    
    return 0;
}
