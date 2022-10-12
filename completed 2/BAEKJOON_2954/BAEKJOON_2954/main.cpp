#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string s;
    getline(cin, s);
    
    for(int i=0; i<s.size(); i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
            cout << s[i];
            i+=2;
        }
        else
            cout << s[i];
    }
    
    return 0;
}
// 웨안뒈;;
/* for(int i=0; i<s.size(); i++){
 if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
     s[i+1]-=s[i+1];
     s[i+2]-=s[i+2];
 }
}
cout << s; */
