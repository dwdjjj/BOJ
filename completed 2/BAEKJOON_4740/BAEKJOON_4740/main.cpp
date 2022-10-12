#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    while(1){
        string s;
        getline(cin,s);
        if(s=="***") break;
        reverse(s.begin(),s.end());
        cout << s <<"\n";
    }

    return 0;
}
