#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 1024+2;
int n, m;
int arr[MAX_N][MAX_N];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(arr, 0, sizeof(arr));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int tmp; cin >> tmp;
            arr[i][j] = arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1] + tmp;
        }
    }
    while(m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        ans = arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
        cout << ans << "\n";
    }
    return 0;
}
