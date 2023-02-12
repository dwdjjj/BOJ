//
//  main.cpp
//  BAEKJOON_15824_capsaicin
//
//  Created by 권영재 on 2023/01/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int n;
const int m = 1e9 + 7;
ll ans = 0;
vector<ll> v;

ll pow(int x, int n) {
    // 기저
    if(n == 0) return 1;
    if(n == 1) return x;
    
    ll tmp = pow(x, n/2);
    
    if(n % 2) return tmp * tmp * x % m;
    
    else return tmp * tmp % m;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<n; i++) {
        ans += pow(2, i) * v[i] - pow(2, n-i-1) * v[i];
        ans %= m;
    }
    cout << ans;
    return 0;
}
