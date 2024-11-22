#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int mod = 1e9;
int n, ans = 0;
int cache[100 + 1][10 + 1];
// 100자리수까지 1~9중 인접한 자리 차이가 1인 수의 개수를 세기
// 상태공간 : n자리 숫자의 각 자리값을 num으로 두고,
int f(int n, int num) {
    if(num < 0 || num > 9) return 0;
    
    int& ret = cache[n][num];
    if(ret != -1) return ret;
    
    if(n == 1) return 1;
    
    // num-1과 num+1의 경우의수를 합하기
    ret = (f(n - 1, num - 1) + f(n - 1, num + 1)) % mod;
    
    return ret;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<= 9; i++) {
        cache[1][i] = 1;
    }
    for(int i=1; i<= 9; i++) {
        ans += f(n, i);
        ans %= mod;
    }
    cout << ans;
    
    return 0;
}
