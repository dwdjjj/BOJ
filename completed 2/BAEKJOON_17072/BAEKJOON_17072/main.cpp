#include <iostream>
using namespace std;
//int arr[403][1200+10];
//int f(int r, int g, int b){
//    return 2126 * r + 7152 * g + 722 * b;
//}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=3*m; j++){
//            cin >> arr[i][j];
//        }
//    }
    int r, g, b;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> r >> g >> b;
            int res = 2126 * r + 7152 * g + 722 * b;
//            int res = f(arr[i][3*j-2], arr[i][3*j-1], arr[i][3*j]);
            if(0 <= res && res < 510000) cout << '#';
            else if(res < 1020000) cout << 'o';
            else if(res < 1530000) cout << '+';
            else if(res < 2040000) cout << '-';
            else cout << '.';
        }
        cout << "\n";
    }
    return 0;
}
