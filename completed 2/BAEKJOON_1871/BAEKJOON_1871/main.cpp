
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>

using namespace std;
int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    while(N--){
        string S;
        cin >> S;
        double sum =0;
        for(int i=0; i<3; i++){
            sum += (S[i]-'A')*pow(26, 2-i);
        }
        // cout << sum;
        char number[4]={0,};
        for(int i=4; i<8; i++){
            number[i-4] = S[i];
        }
        int num = stoi(number);
        // sscanf(number.data(), "%d", num);
        
        if(abs(num-sum)<=100){
            cout << "nice" << "\n";
        }
        else cout << "not nice" << "\n";
    }
    
    
    return 0;
}
