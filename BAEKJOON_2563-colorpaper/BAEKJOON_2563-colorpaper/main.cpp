#include <iostream>
using namespace std;
int arr[100+2][100+2];
int main(int argc, const char * argv[]) {
    int n, ans = 0;
    cin >> n;
    while(n--) {
        int x, y; cin >> x >> y;
        for(int i=y; i<y+10; i++) {
            for(int j=x; j<x+10; j++) {
                arr[i][j] = 1;
            }
        }
    }
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(arr[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}
