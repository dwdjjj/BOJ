//
//  main.cpp
//  BAEKJOON_1563
//
//  Created by 권영재 on 2022/09/21.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 1000+3;
int n;
int cache[MAX_N][2 +2][3 +2];
// 개근상을 받을 수 있는 경우의 수
// 못받는거 : 지각2회 이상 or 결석 3일연속 이상으로
// 그럼 개근상은 지각 없이, 지각한번하고 받을 수 있음. 결석은 연속만 더해주고 나머진 0으로 초기화
int f(int idx, int late, int absent) {
    
    if (idx >= n) {
        return 1;
    }
    
    int& ret = cache[idx][late][absent];
    if (ret != -1) return ret;
    ret = 0;
    
    if (late < 1) ret += f(idx + 1, late + 1, 0);
    if (absent < 2) ret += f(idx + 1, late, absent + 1);
    ret += f(idx + 1, late, 0);
    ret %= 1000000;
    
    return ret;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << f(0, 0, 0);
    return 0;
}
