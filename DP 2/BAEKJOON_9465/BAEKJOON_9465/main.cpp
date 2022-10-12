#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1e6+3;
int cache[MAX][3];
int arr[2][MAX];
int T, n;

// 함수에 변수 두 개 사용
// status가 0이면 바로 왼쪽 열에서 스티커 안 뗌.
// 1이면 위쪽, 2면 오른쪽 스티커를 떼는걸 선택함.
int f(int x, int status){
    if(x==n) return 0;
    if(cache[x][status] != -1) return cache[x][status];
    
    int res = f(x+1, 0);
    if(status != 1) res = max(res, f(x+1, 1) + arr[0][x]);
    if(status != 2) res = max(res, f(x+1, 2) + arr[1][x]);
    
    cache[x][status] = res;
    return res;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        memset(cache, -1, sizeof(cache));
        cout << f(0, 0) << "\n";
        
    }
    return 0;
}
