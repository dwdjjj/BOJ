#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    while(1){
        string s;
        getline(cin,s);
        if(s=="*") break;
        
        bool flag = true;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]==' ')
            {
                if('a'<=s[0]&&s[0]<='z')
                {
                    if(s[0]==s[i+1]||s[0]-'a'==s[i+1]-'A')
                        flag = true;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else if('A'<=s[0]&&s[0]<='Z')
                {
                    if(s[0]==s[i+1]||s[0]-'A'==s[i+1]-'a')
                        flag = true;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag)
            cout << "Y\n";
        else
            cout << "N\n";
    }
    
    return 0;
}
