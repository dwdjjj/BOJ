#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int wine[10004];
int cache[10004][5];
//상태공간정의 : idx번째 포도주를 마시고, 연속 세잔은 못마실 때 마실 수 있는 최대 포도주량
int f(int idx, int cnt) {
    
    if (idx > n) {
        return 0;
    }
    
    int& ret = cache[idx][cnt];
    if (ret != -1) return ret;

    if (cnt == 2) {
        return ret = max(f(idx+2, 1) + wine[idx+2], f(idx+3, 1)+ wine[idx+3]);
    }
    else return ret = max(f(idx+1, cnt+1) + wine[idx+1], f(idx+2, 1) + wine[idx+2]);
    
    return ret;
}
// idx번째에 포도주를 먹거나 안먹고 넘어가면서 연속 세잔은 못마시는 최대 포도주량.
int f2(int idx, int cnt) {
    if (idx > n) {
        return 0;
    }
    
    int& ret = cache[idx][cnt];
    if (ret != -1) return ret;

    if (cnt == 2) {
        return ret = f(idx+1, 0);
    }
    else return ret = max(f(idx+1, cnt+1) + wine[idx], f(idx+1, 0));
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> wine[i];
    }
    cout << f2(1, 0)<<"\n";
    cout<< f2(2,1)<<"\n";
    cout<<f2(3,2)<<"\n";
    cout<<f2(4,0)<<"\n";
    return 0;
}
