#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[1004];
int cache[1004];
// 상태공간 : idx번째의 카드팩을 몇 개씩 사서 총 n개의 카드를 사기 위해 지불해야하는 금액의 최댓값 구하기.
// arr에 들어갈 카드팩들은 i번째에 i개의 카드가 들어잇음.
// ex) 총 4개. 순서대로 1,5,6,7 가격의 카드팩 있으면 2개짜리 두개 사서 10원이 최대
int f(int idx) {
    
    if (idx == 0) {
        return 0;
    }
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    for (int i=1; i<=idx; i++) {
        ret = max(ret, f(idx - i) + arr[i]); // idx번째 사거나 안사거나
    }
    
    return ret;
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    cout << f(n);
    return 0;
}
