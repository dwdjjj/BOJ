#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int n, k;
const int m = 10000;
const int MAX_N = 100+4;
int arr[MAX_N] = {0, };
int cache[MAX_N][4][2];
// 상태공간정의 : idx날에 파스타를 먹을건데, 3일이상 같은 파스타 먹으면 안됨. 입력받은 미리 정해진 날엔 그 파스타를 반드시 먹어야 한다. pasta먹으면서 연달아 먹은 여부 flag.
int f(int idx, int pasta, int flag) { // flag : 1 이어서 안먹음, 0 연이어 먹음
    if (arr[idx] != 0 && arr[idx] != pasta) return 0; //정해진날 다른거 먹으면 실패
    if (idx == n) return 1;
    
    int& ret = cache[idx][pasta][flag];
    if (ret != -1) return ret;
    
    //연속으로 먹었으면
    if (flag) ret = 0;
    else ret = f(idx + 1, pasta, 1);
    
    //연속X
    for (int i=1; i<=3; i++) {
        if (pasta != i) {
            ret = ret + f(idx+ 1, i, 0) % m;
        }
    }
    
    return ret % m;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    cout << f(0, 0, 1);
    return 0;
}
