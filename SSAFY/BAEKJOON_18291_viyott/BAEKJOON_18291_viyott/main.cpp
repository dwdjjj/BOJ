//
//  main.cpp
//  BAEKJOON_18291_viyott
//
//  Created by 권영재 on 2023/01/31.
//

#include <iostream>
typedef long long ll;
using namespace std;
const int mod = 1e9+7;
int T;

ll pow(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return 2;
    
    ll tmp = pow(a, b / 2);
    tmp = tmp * tmp % mod;
    if(b % 2 == 0) return tmp;
    else return tmp * a % mod;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        int n; cin >> n;
        if(n - 2 <= 0) cout << 1 << "\n";
        else cout << pow(2, n - 2) << "\n";
    }
    return 0;
}
