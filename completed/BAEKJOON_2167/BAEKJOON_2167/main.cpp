#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> arr(N,vector<int>(M,0));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    int k;
    cin >> k;
    
    while(k--)
    {
        int i, j, x, y;
        cin >> i >> j;
        cin >> x >> y;
        int sum = 0;
        for(int row=i-1; row<x; row++){
            for(int column=j-1; column<y; column++){
                sum += arr[row][column];
            }
        }
        cout << sum <<"\n";
    }
    
    return 0;
}
