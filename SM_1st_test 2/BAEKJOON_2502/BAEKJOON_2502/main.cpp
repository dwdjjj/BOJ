#include <algorithm>
#include <string.h>
#include <iostream>
#define INF 987654321
using namespace std;
int day, k, res;
// 할머니가 넘어온 날과 그 날 호랑이에게 준 떡의 개수로 첫날, 둘째날에 준 떡의 개수를 구하기.
// 직전날과 그 전전날의 합만큼 호랑이에게 떡을 주니 => 걍 피보나치?
// 상태공간정의 : idx째 날에 준 떡의 개수는 idx-1, idx-2째 날의 떡개수의 합이다.
// 근데 day날 떡개수를 아니까 첫째날 둘째날의 떡갯수를 알고싶음.
// 2 7 9 16 25 <- 41
int cache[33];
//int f(int idx) {
//    if (idx == 1) {
//        return 1;
//    }
//    if (idx == 2) {
//        return 1;
//    }
//
//    int& ret = cache[idx];
//    if (ret != -1) return ret;
//
//    int x = 1, y = 1;
//    for (int i=3; i<=idx; i++) {
//        ret = x + y;
//        x = y, y = ret;
//    }
//    return ret = f(idx-1) + f(idx -2);
//}


//오늘 주는 떡 개수 = 전 날 준 떡 개수 + 전전날 준 떡 개수
//첫 날 x, 둘째 날 y => dp[1] = x, dp[2] = y, dp[3] = x + y, dp[4] = x + y + y ...
//K 최대는 100,000 날짜는 최대 30일 => 300만번밖에 안걸린다. 또, 1<=A<=B 조건있으니 1<=A<=K/2만 체크
pair<int, int> dp[33];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    
    cin >> day >> k;
    dp[1] = {1,0}; dp[2] = {0,1};
    
    int j;
    for (int i=3; i<= day; i++) {
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }
    
    for (int i=1; i<=k/2; i++) {
        if ((k - dp[day].first * i) % dp[day].second == 0) {
            j = (k - dp[day].first * i) / dp[day].second;
            if (j >= i) {
                cout << i << '\n' << j;
                return 0;
            }
        }
    }
    

    
    return 0;
}
