
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string S;
        getline(cin, S);
        int g=1, b=1;
        for(int i=0; S[i]; i++){
            if(S[i]=='g'||S[i]=='G') g++;
            else if(S[i]=='b'||S[i]=='B') b++;
        }
        if(g>b) cout << S << " is GOOD\n";
        else if(g<b) cout << S << " is A BADDY\n";
        else cout << S << " is NEUTRAL\n";
        /*if(g>b) hero = "is GOOD";
        else if(b<g) hero = "is A BADDY";
        else if(b==g) hero = "is NEUTRAL";
        cout << S << " " << hero << "\n";*/
    }
    
    return 0;
}
