#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 2187+3;
int n;
// vector<vector<int>>v(MAX,vector<int>(MAX, 0));
// 숫자 다같은지 확인 -> 9등분 후 다시체크 -> 다른애들 또 9등분->(1X1)됨
int arr[MAX][MAX], res[3];
bool check(int n, int m, int k) { // n행m열에서 시작해 k개수만큼 체크. 다르면 false
    
    for(int i=n; i<n+k; i++){
        for(int j=m; j<m+k; j++){
            if(arr[n][m] != arr[i][j]) return false;
        }
    }
    return true;
}
void f(int x, int y, int n){ // check가 참이면 종이 모두 같음. 숫자개수 한개 더해줌(인덱스-1부터니까 +1해줌)
    if(check(x, y, n)) {
        res[arr[x][y]+1]++;
        return;
    }
    int m = n/3; //m 3등분
    for(int i=0; i<3; i++){ //9개 분할정복
        for(int j=0; j<3; j++){
            f(x+i*m, y+j*m, m);
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(arr, 0, sizeof(arr));
    memset(res, 0, sizeof(res));
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    f(0, 0, n);
    for(int i=0; i<3; i++) cout << res[i] << "\n";
    return 0;
}

