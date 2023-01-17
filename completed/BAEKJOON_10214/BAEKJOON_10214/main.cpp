
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    while(T--){
        int Y[9]={0,}, K[9]={0,};
        int scoreY=0, scoreK=0;
        for(int i=0; i<9; i++){
            cin >> Y[i] >> K[i];
            scoreY+=Y[i];
            scoreK+=K[i];
        }
        if(scoreY>scoreK) cout << "Yonsei" << "\n";
        else if(scoreY<scoreK) cout << "Korea" << "\n";
        else if(scoreY==scoreK) cout << "Draw" << "\n";
    }
    
    return 0;
}
