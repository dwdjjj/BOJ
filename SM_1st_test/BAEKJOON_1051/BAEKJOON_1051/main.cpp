#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans;
int arr[53][53];
bool flag = true;
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    int len = min(n, m) + 1;
    while (len--) {
//        cout << len << " ";
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if(i + len - 1 >= n || j + len - 1 >= m) break; //범위 벗어나는 경우
                if (arr[i][j] == arr[i + len -1][j + len - 1] && arr[i][j] == arr[i][j + len - 1]
                    && arr[i][j] == arr[i + len - 1][j]) {
                    if(flag) {
                        ans = len * len;
                        flag = false;
                    }
                }
            }
        }
//        cout << ans << "\n";
        if(!flag) break;
    }
    cout << ans;
    return 0;
}
