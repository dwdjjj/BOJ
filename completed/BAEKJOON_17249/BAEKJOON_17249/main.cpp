
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    string S;
    cin >> S;
    int left=0, right=0;
    for(int i=0; i<S.size(); i++){
        if(S[i]=='@') {
            left++;
        }
        else if(S[i]=='0') {
            break;
        }
    }
    for(int j=(int)S.size(); j>0; j--){
        if(S[j]=='@') {
            right++;
        }
        else if(S[j]=='0') {
            break;
        }
    }
    cout << left << " " << right;
    return 0;
}
