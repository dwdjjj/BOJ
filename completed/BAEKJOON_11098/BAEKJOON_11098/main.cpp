
#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {

    int T;
    cin >> T;
    
    while(T--){
        int p;
        cin >> p; // p = 고려해야할 선수의 수
        string S[p]; // 선수 이름
        int* C = new int [p];
        for(int i=0; i<p; i++){
            cin >> C[i]; cin >> S[i];
        }
        int max=0, tmp=0;
        for(int i=0; i<p; i++){
            if(C[i]>max) {
                max = C[i];
                tmp = i;
            }
        }
        cout << S[tmp] << "\n";
        
    }
    
    return 0;
}
