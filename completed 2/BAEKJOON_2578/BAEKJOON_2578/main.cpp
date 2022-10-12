#include <vector>
#include <iostream>
using namespace std;
const int N = 5;
int bingo[N][N]={0,};

void change_bingo(int call){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(bingo[i][j]==call)
            {
                bingo[i][j]=0;
                return;
            }
        }
    }
}
bool check_bingo(){
    int count=0, sum_x=0, sum_y=0;
    for(int i=0; i<N; i++){
        int sum_row = 0;
        for(int j=0; j<N; j++){
            sum_row += bingo[i][j];
        }
        if(sum_row==0) count++;
    }
    for(int i=0; i<N; i++){
        int sum_col=0;
        for(int j=0; j<N; j++){
            sum_col += bingo[j][i];
        }
        if(sum_col==0) count++;
    }
    for(int i=0; i<N; i++){
        sum_x += bingo[i][i];
    }
    if(sum_x==0) count++;
    
    for(int i=0; i<N; i++){
        int j=N-i-1;
        sum_y += bingo[i][j];
    }
    if(sum_y==0) count++;
    
    if(count>=3) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio();
    for(int i=0;  i<N; i++){
        for(int j=0; j<N; j++){
            cin >> bingo[i][j];
        }
    }
    int check;
    for(int i=0;  i<25; i++){
        
        cin >> check;
        change_bingo(check);
        if(check_bingo())
        {
            cout << i+1 << "\n";
            break;
        }
    }
    
    return 0;
}
