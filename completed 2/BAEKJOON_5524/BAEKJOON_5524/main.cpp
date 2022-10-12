#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int n;
    cin >>n;
    
    while(n--)
    {
        string s;
        cin >> s;
        
        for(int i=0; i<s.size(); i++)
        {
            if(isupper(s[i]))
                s[i] = s[i]-'A'+'a';
        }
        
        cout << s << "\n";
    }
    
    return 0;
}
