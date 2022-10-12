
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int N, check=26;
    cin >> N;
    string S;
    
    int count[26] = {0,};
    
    while(N--){
        cin >> S;
        count[S[0]-'a']++;
    }
    for(int i=0; i<26; i++){
        if(count[i]<5){
            check--;
        }
        else if(count[i]>=5){
            cout << (char)(i+'a');
        }
    }
    if(check==0) cout << "PREDAJA";
    return 0;
}
