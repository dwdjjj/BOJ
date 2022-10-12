
#include <iostream>
const int MAX = 10+2;
int arr[MAX][MAX]={0,};
int n, m, h;
int nowX, nowY;
using namespace std;
int main(int argc, const char * argv[]) {
    cin >> n >> m >> h;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==1){
                nowX=i;
                nowY=j;
            }
        }
    }
    return 0;
}
