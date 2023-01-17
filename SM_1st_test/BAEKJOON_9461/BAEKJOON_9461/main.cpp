#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 100+4;
int t, n;
long long cache[MAX_N];
//p4 = p1 + p2, p5 = p2+p3, p6=p3+p4
// idx번째의 수는 idx-3, idx-2번째 수를 더한 수이다
long long f(int idx) {
    if (idx == 1 || idx == 2 || idx == 3) {
        return 1;
    }
    long long& ret = cache[idx];
    if (ret != -1) return ret;
    
    else return ret = f(idx-2)+f(idx-3);
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f(n) << '\n';
    }
    return 0;
}
