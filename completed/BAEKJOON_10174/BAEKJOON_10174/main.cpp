#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        
        /*string revS(s);
        reverse(revS.begin(), revS.end());
        if(strcasecmp(s.c_str(), revS.c_str())==0)
            cout << "Yes\n";
        else
            cout << "No\n"; // reverse함수로 뒤집어서 revS에 저장한 후에 둘이 같은지 비교*/
        bool flag = true;
        for(int i=0; i<s.size(); i++){
            s[i] = tolower(s[i]); s[s.size()-i-1] = tolower(s[s.size()-i-1]);
            if(s[i]==s[s.size()-i-1])
                flag = true;
            else
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
    return 0;
}
