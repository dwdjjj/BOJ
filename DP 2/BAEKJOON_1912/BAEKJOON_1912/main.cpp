#include <algorithm>
#include <string.h>
#include <iostream>
#define INF 987654321
using namespace std;
int n;
int arr[100000+4];
int cache[100000+4][2+1];
// 7000*7000
// idx번째에서 연속한 다음 수를 더할지 말지 더한다면 그 합이 가장 크게 되도록
// 캐시배열은 절대 나올 수 없는 값으로 초기화할 것.
int f(int idx, bool flag) {
    
    if (idx == n && !flag) {
        return -INF;
    }
    if (idx == n) {
        return 0;
    }
    
    
    int& ret = cache[idx][flag];
    if (ret != INF) return ret;
    
    if (flag) {
        return ret = max(f(idx+1, 1) + arr[idx], f(n, 1)); // 0 은 성공적인 종료의미
                                                //f(n, 1)이 배열 뒤 더 안보겠다는 의미
    }
    else {
        return ret = max(f(idx+1, 1) + arr[idx], f(idx+1, 0));
    }
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cache[i][j] = INF;
        }
    }
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << f(0, 0);
    return 0;
}
