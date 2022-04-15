#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

int T, W;
int jadoo[1003];
int cache[1003][33];
// idx초에 자두를 받아먹을 건데, 현재 남은기회가 chance만큼있다. 현재 cur위치해있을 때 받아먹은 자두의 최대 개수를 반환하는 함수
int f(int idx, int chance, int cur) {
    
    if (idx == T) {
        return 0;
    }
    
    int& ret = cache[idx][chance];
    if (ret != -1) return ret;
    
    if (chance == 0) {
        if (jadoo[idx] == cur) return ret = f(idx+1, chance, cur) + 1;
        else return ret = f(idx+1, chance, cur);
    }
// 뉴딜피드백
//    if (chance == 0)
//        return ret = f(idx+1, chance, cur) + (jadoo[idx] == cur);
    
    // 시작위치 : 1  // 1=>2 2=>1 cur%2+1 || cur==1 ? 2 : 1
    if (jadoo[idx] == cur) return ret = max(f(idx + 1, chance, cur) +  1, f(idx + 1, chance-1, cur % 2 + 1));
    if (jadoo[idx] != cur) return ret = max(f(idx + 1, chance-1, cur % 2 + 1) + 1, f(idx + 1, chance, cur));
        
    return ret;
}
int main(int argc, const char * argv[]) {
    cin >> T >> W;
    memset(cache, -1, sizeof(cache));
    for (int i=0; i<T; i++) {
        cin >> jadoo[i];
    }
    cout << f(0, W, 1);
    return 0;
}
