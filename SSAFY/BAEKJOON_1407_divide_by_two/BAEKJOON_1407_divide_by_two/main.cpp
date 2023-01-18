//
//  main.cpp
//  BAEKJOON_1407_divide_by_two
//
//  Created by 권영재 on 2023/01/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
ll a, b;
// 0 1 0 2 0 1 0 3 0 1 // 2로 한번 나눠지는 갯수 : 5
// 2로 2번 나눌 수 있는 개수 : 2개
// 2로 3번 나눌 수 있는 개수 : 1개
// f(A) = f(1) + f(2) + ... f(A)
// 1 2 3 4 5 6 7 8 9 10
//   2   4   6   8
//       4       8
//               8
// 2로 나누면 시간초과남
// 2의 거듭제곱으로 생각. 1~n까지의 2의 거듭제곱수의 합
// 0, 1, 1, 2, 2, 2, 2, 3, 3, 3,
ll f(ll n) {
    ll x = 1, ans = n;
    while(1) {
        if(x > n) break;
        x *= 2;
        ans += (n / x) * (x / 2);
        cout << ans << " ";
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> a >> b;
    
    cout << f(b) - f(a - 1);
    
    return 0;
}
