#include <iostream>
using namespace std;
const int MAX_N = 2000+3;
int n, m, k;
int cntB[MAX_N][MAX_N];
int cntW[MAX_N][MAX_N];
char arr[MAX_N][MAX_N];
int preSumB[MAX_N][MAX_N];
int preSumW[MAX_N][MAX_N];
int ans = 0;
bool flag = true;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }
    
    // B로 시작하는 체스판, W로 시작하는 체스판 나눠생각
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(arr[i][j] =='B') {
                if(i%2) {
                    if(j%2) flag = true;
                    else flag = false;
                }
                else {
                    if(j%2) flag = false;
                    else flag = true;
                }
            }
            else if (arr[i][j] == 'W') {
                if(i%2) {
                    if(j%2) flag = false;
                    else flag = true;
                }
                else {
                    if(j%2) flag = true;
                    else flag = false;
                }
            }
            if(flag) {
                cntB[i][j] = 1;
                cntW[i][j] = 0;
            }
            else if(!flag) {
                cntB[i][j] = 0;
                cntW[i][j] = 1;
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            preSumB[i][j] = preSumB[i][j-1] + preSumB[i-1][j] - preSumB[i-1][j-1] + cntB[i][j];
            preSumW[i][j] = preSumW[i][j-1] + preSumW[i-1][j] - preSumW[i-1][j-1] + cntW[i][j];
        }
    }
//
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=m; j++) {
//            cout << cntB[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=m; j++) {
//            cout << cntW[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=m; j++) {
//            cout << preSumB[i][j] << " ";
//        }
//        cout << "\n";
//    }
    
    if((n == m) == k) cout << min(preSumB[k][k], preSumW[k][k]);
    else {
        for(int i=k; i<=n; i++) {
            for(int j=k; j<=m; j++) {
                int tmpB = preSumB[i][j] - preSumB[n-k][j] - preSumB[i][m-k] + preSumB[n-k][m-k];
                int tmpW = preSumW[i][j] - preSumW[n-k][j] - preSumW[i][m-k] + preSumW[n-k][m-k];
                ans = min(tmpB, tmpW);
            }
        }
        cout << ans;
    }
    
    return 0;
}
// 흰색 검정색 시작 정하고 알맞은칸인지 체크하는 로직
//if((i % 2)) { // 홀수행
//    if((j % 2)) { // 홀수열
//        if(arr[i][j] =='B') { // B면
//            cntB[i][j] = 1;
//            cntW[i][j] = 0;
//        }
//        else { // W면
//            cntB[i][j] = 0;
//            cntW[i][j] = 1;
//        }
//    }
//    else { // 짝수열
//        if(arr[i][j] =='B') {
//            cntB[i][j] = 0;
//            cntW[i][j] = 1;
//        }
//        else {
//            cntB[i][j] = 1;
//            cntW[i][j] = 0;
//        }
//    }
//}
//else {
//    if((j % 2)) {
//        if(arr[i][j] =='B') {
//            cntB[i][j] = 0;
//            cntW[i][j] = 1;
//        }
//        else {
//            cntB[i][j] = 1;
//            cntW[i][j] = 0;
//        }
//    }
//    else {
//        if(arr[i][j] =='B') {
//            cntB[i][j] = 1;
//            cntW[i][j] = 0;
//        }
//        else {
//            cntB[i][j] = 0;
//            cntW[i][j] = 1;
//        }
//    }
//}
