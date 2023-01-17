#include <iostream>
using namespace std;
const int MAX_N = 2000+3;
int n, m, k;
int cntB[MAX_N][MAX_N];
int cntW[MAX_N][MAX_N];
char arr[MAX_N][MAX_N];
int preSumB[MAX_N][MAX_N];
int preSumW[MAX_N][MAX_N];
int ans = 987654321;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    
    // B로 시작하는 체스판, W로 시작하는 체스판 나눠생각
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int tmp;
            if((i+j)%2 == 0) {
                tmp = arr[i][j] != 'B' ? 1 : 0;
            }
            else {
                tmp = arr[i][j] == 'B' ? 1 : 0;
            }
            preSumB[i+1][j+1] = preSumB[i+1][j] + preSumB[i][j+1] - preSumB[i][j] + tmp;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int tmp;
            if((i+j)%2 == 0) {
                tmp = arr[i][j] != 'W' ? 1 : 0;
            }
            else {
                tmp = arr[i][j] == 'W' ? 1 : 0;
            }
            preSumW[i+1][j+1] = preSumW[i+1][j] + preSumW[i][j+1] - preSumW[i][j] + tmp;
        }
    }
    for(int i=1; i<=n-k+1; i++) {
        for(int j=1; j<=m-k+1; j++) {
            int tmpB = preSumB[i+k-1][j+k-1] - preSumB[i+k-1][j-1] - preSumB[i-1][j+k-1] + preSumB[i-1][j-1];
            int tmpW = preSumW[i+k-1][j+k-1] - preSumW[i+k-1][j-1] - preSumW[i-1][j+k-1] + preSumW[i-1][j-1];
            ans = min(ans, min(tmpB, tmpW));
        }
    }
    cout << ans;
    
    return 0;
}
