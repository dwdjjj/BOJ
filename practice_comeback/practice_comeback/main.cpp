#include <iostream>
using namespace std;
int H, W;

int main(int argc, const char * argv[]) {
    cin >> H >> W;
    char arr[H][W];
    int res[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> arr[i][j];
            //cout << arr[i][j];
            if(arr[i][j] == 'c') res[i][j] = 0;
            else res[i][j] = -1;
        }
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(res[i][j] == 0){
                int cnt = 1;
                for(int k=j+1; k<W; k++){
                    if(res[i][k] == -1) res[i][k] = cnt++;
                    else break;
                }
            }
        }
    }
    
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
