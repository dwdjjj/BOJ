#include <vector>
#include <iostream>
using namespace std;
int r, c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char arr[12][12];

int CheckUturn() {
    int ans = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (arr[i][j] == 'X') continue;
            
            int cnt = 0;
            for (int k=0; k<4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (arr[ny][nx] == '.') cnt++;
            }
            
            if (cnt <= 1) {
                ans = 1;
                break;
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << CheckUturn();
    
    return 0;
}
