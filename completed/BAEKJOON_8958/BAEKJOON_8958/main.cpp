
#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int testN;
    cin >> testN;
    string OX;
    
    while(testN--){
        int score=0, count=0;
        cin >> OX;
        for(int i=0; i<OX.size(); i++){
            if(OX[i]=='O') {
                ++count;
                score += count;
            }
            else if(OX[i]=='X'){
                count = 0;
                score += count;
            }
        }
        cout << score << "\n";
    }
    
    return 0;
}
