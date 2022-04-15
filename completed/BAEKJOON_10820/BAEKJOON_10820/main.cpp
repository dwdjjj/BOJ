#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(1) {
        
        string s;
        getline(cin, s);
//            if(cin.eof()) break;
        
        int smallAlph = 0, largeAlph = 0, num = 0, blank = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') smallAlph++;
            if(s[i] >= 'A' && s[i] <= 'Z') largeAlph++;
            if(s[i] >= '0' && s[i] <= '9') num++;
            if(s[i] == ' ') blank++;
        }
        if(smallAlph + largeAlph + num + blank == 0) break;
        else cout << smallAlph << " " << largeAlph << " " << num << " " << blank << "\n";
    }
    
    
    return 0;
}

