
#include <iostream>
#define MAX 105
using namespace std;
int n, x, y; // x 가로로 누울 수 있는 자리 개수, y 세로.
char arr[MAX][MAX];
int main(int argc, const char * argv[]) {
    cin >> n;
    
//    for(int i = 0; i < MAX; i++) {
//        for(int j = 0; j < MAX; j++)
//            arr[i][j] = 'X';
//    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
        arr[i][n] = 'X';
        arr[n][i] = 'X';
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (arr[i][j] == '.' && arr[i][j+1] == '.' && arr[i][j+2] == 'X') {
                x++;
            }
            if (arr[j][i] == '.' && arr[j+1][i] == '.' && arr[j+2][i] == 'X') {
                y++;
            }
        }
    }
    
    cout << x << " " << y;
    return 0;
}
