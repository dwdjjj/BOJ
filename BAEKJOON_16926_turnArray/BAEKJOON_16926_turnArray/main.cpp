#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 300+3;
int n, m, r;
int arr[MAX_N][MAX_N]; // 5 x 6 이면 두바퀴돔, 6 x 6은 3바퀴....
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


void rotate() {
    int cnt = min(n, m) / 2; // 돌릴 사각형 수

    for (int x = 0; x < cnt; x++) {
        int numN = n - x - 1, numM = m - x - 1;
        int tmp = arr[x][x];
        
        // 윗변 : 왼쪽으로
        for (int i = x; i < numM; i++) {
            arr[x][i] = arr[x][i+1];
        }
        // 오른변 : 위로
        for (int i=x; i<numN; i++) {
            arr[i][numM] = arr[i+1][numM];
        }
        // 아랫변 : 오른쪽으로
        for (int i=numM; i > x; i--) {
            arr[numN][i] = arr[numN][i-1];
        }
        
        for (int i=numN; i >x; i--) {
            arr[i][x] = arr[i-1][x];
        }
        arr[x+1][x] = tmp;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> r;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i=0; i<r; i++) rotate();
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
