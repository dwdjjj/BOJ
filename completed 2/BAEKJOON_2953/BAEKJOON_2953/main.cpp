#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    /*int score[5]={0,};
    int winner=0, max=0;
    for(int i=1; i<=5; i++){
        int a, sum=0;
        for(int j=0; j<4; j++){
            cin >> a;
            sum+=a;
        }
        score[i]=sum;
        if(score[i]>max){
            max = score[i];
            winner=i;
        }
        // cout << winner;
    }
    cout << winner << " " << max;*/
    
    int winner=0, max=0;
    for(int i=1; i<=5; i++){
        int a, sum=0;
        for(int j=0; j<4; j++){
            cin >> a;
            sum+=a;
        }
        if(sum > max){
            max = sum;
            winner = i;
        }
        //cout << winner << " " << max << "\n";
    }
    cout << winner << " " << max;
    
    return 0;
}



