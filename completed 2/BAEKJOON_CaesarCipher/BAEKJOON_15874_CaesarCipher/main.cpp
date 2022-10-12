
#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {

    int k;
    cin >> k; //민 횟수
    int slength;
    cin >> slength;
    cin.ignore();
    //char s[slength];
    // cin.getline(s,slength);
    string s;
    getline(cin,s);
    for(int i=0; i<slength; i++){
        if('a'<=s[i]&&s[i]<='z'){           //islower(s[i])써도 됨.
            s[i] = (s[i]-'a'+k)%26+'a';
        }
        else if('A'<=s[i]&&s[i]<='Z'){      //isupper써도 됨.
            s[i] = (s[i]-'A'+k)%26+'A';
        }
        cout << s[i];
        
    }
        
    return 0;
}
