#include <vector>
#include <iostream>
using namespace std;
const int MAX = 103;
int n, k;
//int arr[MAX][MAX];
int tmp;
int res[MAX][MAX];

int main(int argc, const char * argv[]) {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
//            cin >> arr[i][j];
            cin >> tmp;
            
            for(int x = i*k; x < i*k + k; x++){
                for (int y = j*k; y < j*k + k; y++) {
//                    res[x][y] = arr[i][j];
                    res[x][y] = tmp;
                }
            }
        }
    }
    for(int i=0; i<n*k; i++){
        for (int j=0; j<n*k; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
