#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    while(1){
        string s;
        getline(cin, s);
        
        if(s=="#") break;
        
        bool isVisited[26]={0,};
        
        for(int i=0; i<s.size(); i++){
            if('A'<=s[i]&&s[i]<='Z')
                s[i] += 'a' - 'A';
            isVisited[s[i]-'a'] = true;
        }
        int count = 0;
        for(int i=0; i<26; i++){
            if(isVisited[i])
                count++;
        }
        cout << count << "\n";
    
    }

    return 0;
}
