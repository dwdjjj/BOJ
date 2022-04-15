#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[1004];
int cache[1004][1004];
// '이전숫자보다 크면' 과거만 미래x
// 상태공간정의 : idx번째 숫자가 이전숫자보다 크면 카운트하는. 증가하는 부분수열의 길이 최댓값 구하는 함수
int f(int idx, int last) {
    
    if (idx == n+1) return 0;
    
    int& ret = cache[idx][last];
    if (ret != -1) return ret;
    
    if (last < arr[idx]) {
        return ret = max(f(idx + 1, arr[idx]) + 1, f(idx + 1, last));
    }
    else return ret = f(idx + 1, last);
    
    return ret;
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    arr[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    cout << f(1, arr[0]);
    return 0;
}
