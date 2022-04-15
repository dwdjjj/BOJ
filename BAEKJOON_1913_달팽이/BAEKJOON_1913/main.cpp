//달팽이 드가자~
#include <vector>
#include <iostream>
using namespace std;
const int MAX_N = 1000;
int arr[MAX_N][MAX_N]={0,};
int N;
int goY[4] = {1, 0, -1, 0}, goX[4] = {0, 1, 0, -1};

bool is_in_board(int y, int x){
    if(0<=y && y<N && 0<=x && x<N) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    // vector<vector<int>>arr(N,vector<int>(N,0));
    int nowY = 0, nowX = 0, d=0, count = N * N;
    
    while(1){
        arr[nowY][nowX] = count--;
        if(count==0) break;
        int nextY, nextX;
        nextY = nowY + goY[d];
        nextX = nowX + goX[d];
        
        if(!is_in_board(nextY, nextX) || arr[nextY][nextX]!=0) {
            d= (d+1)%4;
            nextY = nowY + goY[d];
            nextX = nowX + goX[d];
        }
        nowY = nextY;
        nowX = nextX;
    }
    
    int X, targetX=0, targetY=0;
    cin >> X;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]==X){
                targetX = i+1;
                targetY = j+1;
            }
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << targetX << " " << targetY;
    
    
    
    return 0;
}
