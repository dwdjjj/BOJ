#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int v;
    cin >> v;
    string s;
    cin >> s;
    int A=0, B=0;
    for(int i=0; i<v; i++){
        if(s[i]=='A')
            A++;
        else if(s[i]=='B')
            B++;
    }
    if(A>B)
        cout << "A";
    else if(A<B)
        cout << "B";
    else cout << "Tie";
    
    return 0;
}
