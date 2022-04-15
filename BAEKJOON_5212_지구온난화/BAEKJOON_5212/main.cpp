#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
const int MAX_N = 10+2;
int r, c;
vector <pair<int, int>> ans;
char arr[MAX_N][MAX_N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
//bool is_in_board(int y, int x) {
//    if (0 < x && x < c && 0 < y && y < r) return true;
//    else return false;
//}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    
    for (int i=0; i<MAX_N; i++) {
        for (int j=0; j<MAX_N; j++) {
            arr[i][j] = '.';
        }
    }
    
    for (int i=1;i<=r;i++){
           for (int j=1;j<=c;j++){
               cin >> arr[i][j];
           }
    }
    
//    for (int i=1; i<=r; i++) {
//        string s; cin >> s;
//        for (int j=1; j<=c; j++) {
//            arr[i][j] = s[j-1];
//        }
//    }
    
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (arr[i][j] == '.') continue;
            int cnt = 0;
            for (int k=0; k<4; k++) {
                int nextR = i + dy[k], nextC = j + dx[k];
                if (arr[nextR][nextC] == '.') cnt++;
            }
            if (cnt >= 3) {
                ans.push_back({i, j});
            }
        }
    }
    for (int i=0; i<ans.size(); i++) {
//        cout << ans[i].first << " " << ans[i].second << "\n";
        arr[ans[i].first][ans[i].second] = '.';
    }
    int minR = MAX_N, maxR = 0, minC = MAX_N, maxC = 0;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (arr[i][j] == 'X') {
                minR = min(minR, i);
                maxR = max(maxR, i);
                minC = min(minC, j);
                maxC = max(maxC, j);
            }
        }
    }
    for (int i=minR; i<=maxR; i++) {
        for (int j=minC; j<=maxC; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}

