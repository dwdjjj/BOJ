
#include <iostream>
using namespace std;
int n, m;
const int MAX = 10+2;
bool flag = false; // 지뢰 깟는지 안깟는지
char arr[MAX][MAX]={'.', };
char open[MAX][MAX]={'.', };
char res[MAX][MAX]={'.', };
int dx[]={0,0,-1,1,-1,-1,1,1};
int dy[]={-1,1,0,0,-1,1,-1,1};

char f(int x, int y){
    int cnt=0, nX, nY;
    for(int i=0; i<8; i++){
        nX = x + dx[i];
        nY = y + dy[i];
        if(arr[nX][nY]=='*') cnt++;
    }
    return '0' + cnt;
}
void boom(){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(arr[i][j]=='*')
                res[i][j]='*';
            else if(open[i][j] == 'x') res[i][j] = f(i, j);
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin >> open[i][j];
        }
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(open[i][j]=='x'){
                if(arr[i][j]=='*') {
                    flag = true;
                }
                else res[i][j] = f(i, j);
            }
            else if(open[i][j] == '.') res[i][j] = '.';
        }
    }
    if(flag) boom();
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout << res[i][j];
        }
        cout << '\n';
    }
    return 0;
}
