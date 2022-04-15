#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 10000 +3;
pair<int, int> Candy[MAX_N/2];
int n;
double m;
int cache[MAX_N];
// cost원으로 사탕을 사가면서(쪼개기X, 여러개O) 가지고 있는 돈 m만큼으로 살 수 있는 칼로리합 최대값 구하기.
int f(int cost) {
    if (cost == 0) {
        return 0;
    }
    
    int& ret = cache[cost];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i=0; i<n; i++) {
        if (Candy[i].second <= cost) {
            ret = max(ret, f(cost - Candy[i].second) + Candy[i].first);
        }
    }
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> m;
        // rounding error 발생할 수 있는 문제가 생김!
        // int로 바꿀때 소수점아래를 버림. 따라서 버려도 문제없도록 반올림을 위해 0.5더해주기
        // 부동소수점 까다로운 이유는 2진법과 10진법의 차이가 커서.
        // ex) 1/10은 0.1이지만 이는 0.0001100110011...으로도 표현된다.
        int Mi = (int)(m * 100 + 0.5);
        if (n == 0 && m == 0.00) break;
        
        for (int i=0; i<n; i++) {
            int c; double p; cin >> c >> p;
            int Pi = (int)(p * 100 + 0.5);
            Candy[i] = {c, Pi};
        }
        cout << f(Mi) << "\n";
    }
    return 0;
}
