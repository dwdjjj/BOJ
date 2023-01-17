
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    cin.ignore();
    while(N--){
        string S;
        getline(cin, S);
        if(S[0]-'Z'>0){
            S[0] = toupper(S[0]);
        }
        cout << S << "\n";
    }
    return 0;
}

