//
//  main.cpp
//  BAEKJOON_1629
//
//  Created by 권영재 on 2023/01/19.
//

#include <iostream>
typedef long long ll;
using namespace std;
ll a, b, c;

ll f(ll a, ll b, ll c) {
    if(b == 0) return 1;
//    if(b == 1) return a % c;
    
    ll tmp = f(a, b/2, c);
    tmp = tmp * tmp % c;
    if(b % 2 == 0) return tmp;
    else return tmp * a % c;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> a >> b >> c;
    cout << f(a, b, c);
    return 0;
}
