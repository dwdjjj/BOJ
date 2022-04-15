#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
//2x1, 1x2타일로 2xn크기의 직사각형을 태우는 방법의 수 구하기.
// 1 -> 1
// 2 -> 2
// 3 -> 3
// 4 -> 5
// 방법의수 : 성공할 때 return 0, 실패시 return INF or -INF로 진행되는 최대최소 DP와 달리
// 방법의 수는 이 방법도 된다 싶으면 +1해주는 방식인가?
using namespace std;
const int MAX_N = 1000+4;
int n;
int cache[MAX_N];
// 상태공간 : 피보나치인듯?
int f(int x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    
    int& ret = cache[x];
    if (ret != -1) return ret;
    
    return ret = f(x-1) % 10007 + f(x-2) % 10007;
}
int main(int argc, const char * argv[]) {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout << f(n) % 10007;
    return 0;
}
