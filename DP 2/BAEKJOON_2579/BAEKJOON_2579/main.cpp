#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int stair[303];
int cache[303][3];
// idx번째의 계단을 밟아서 점수를 먹을건데, 연속 세개 밟으면 안됨.
// 근데, 마지막은 반드시 밟아야 함
// 이 규칙으로 오르면서 얻을 수 있는 최대 점수 반환 함수.
int f(int idx, int cnt) {
    if (idx == n) {
        return 0;
    }
    if (idx > n) {
        return -987654321;
    }
    
    int& ret = cache[idx][cnt];
    if (ret != -1) return ret;
    
//    if (idx == n-2 && cnt == 1) {
//        return ret = f(idx+1, cnt+1) + stair[idx+1];
//    }
//    if (idx == n-3 && cnt == 2) {
//        return ret = f(idx+2, 1) + stair[idx+2];
//    }
    
    if (cnt == 2) {
        return ret = f(idx + 2, 1) + stair[idx+2];
    }
    else {
//        if (idx == n-1) return ret = f(idx+1, cnt+1) + stair[idx+1];
//        if (idx == n-2) return ret = f(idx+2, 1) + stair[idx+2];
        return ret = max(f(idx+1, cnt+1) + stair[idx+1], f(idx+2, 1) + stair[idx+2]);
    }
    
    return ret;
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> stair[i];
    }
    cout << f(0, 0);
    return 0;
}
