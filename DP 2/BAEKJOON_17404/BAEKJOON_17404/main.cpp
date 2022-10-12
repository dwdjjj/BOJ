#include <algorithm>
#include <string.h>
#include <iostream>
#define INF 987654321
#define MAX_N 1000 + 4
using namespace std;
int n, tmp = INF, ans = INF;
int arr[MAX_N][5];
int cache[MAX_N][5];
int firstC = 0;
enum color {
    NONE,
    RED,
    GREEN,
    BLUE
};
//
// 
// 상태공간정의 : idx번째집에 색을 칠할건데, 1번집은 2번과 n번째의 집색과 다르게 / n번집은 n-1번,1번과 다르게 / i번 집은 i-1,i+1과 다르게 칠하는 비용의 최솟값 구하기. 즉, idx번째는 이전 집과 색이 다르게 + n번집은 1번집과 다르게!
int f(int idx, int lastC) {
    
    if (idx == n) return 0;
    
    int& ret = cache[idx][lastC];
    if (ret != -1) return ret;
    
    ret = INF;
    
    if (idx == 1) firstC = lastC;
    
    for (int i=1; i<=3; i++) {
        if (idx == n-1) {
            if (lastC != i && firstC != i) {
                ret = min(ret, f(idx+1, i) + arr[idx][i]);
            }
        }
        else if (lastC != i) ret = min(ret, f(idx+1, i)+ arr[idx][i]);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=3; i++) {
        memset(cache, -1, sizeof(cache));
        int tmp = f(1, i) + arr[0][i];
        ans = tmp > ans ? ans : tmp;
    }
    cout << ans;
    return 0;
}
