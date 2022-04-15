#include <string.h>
#include <iostream>
#define INF 987654321
using namespace std;
int n;
int arr[1003][5];
int cache[1003][5];
enum color {
    NONE,
    RED,
    GREEN,
    BLUE
};
// idx번째에 집을 칠할건데, 이전 집 색을 받아서 그색이랑은 안겹치게 칠하는 비용의 최솟값 구하는 함수
int f(int idx , int lastC) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    if (idx == n) {
        return 0;
    }
    
    int& ret = cache[idx][lastC];
    if (ret != -1) return ret;

    ret = INF;
    
    if (lastC != RED) ret = min(ret, f(idx + 1, RED) + arr[idx][RED]); // 빨간색으로 칠하면
    if (lastC != GREEN) ret = min(ret, f(idx + 1, GREEN) + arr[idx][GREEN]);
    if (lastC != BLUE) ret = min(ret, f(idx + 1, BLUE) + arr[idx][BLUE]);
    
    return ret;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=1; j<4; j++) {
            cin >> arr[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    
    cout << f(0, NONE);
    return 0;
}
