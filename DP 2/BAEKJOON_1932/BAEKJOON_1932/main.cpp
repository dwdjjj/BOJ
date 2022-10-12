#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int arr[503][503];
int cache[503][503];
// 상태공간 : idx번째층에서 아래층으로 점점 내려가면서 숫자를 더할껀데, 현재층의 선택된 수에서 왼쪽아래or오른쪽 아래만 선택 가능. 이렇게 선택된 수의 합이 최대가 되도록 하는 함수
// 현재 위치 알아야되니까 idx층 말고 x,y위치에서?
int f(int y, int x) {
    
    if (y == n) {
        return 0;
    }
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    
    return ret = max(f(y+1, x) + arr[y][x], f(y+1, x+1) + arr[y][x]);
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    cout << f(0, 0);
    return 0;
}
