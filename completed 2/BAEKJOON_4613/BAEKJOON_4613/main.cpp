#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    while(1){
        string s;
        getline(cin, s);
        if(s=="#")
            break;
        
        int sum=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
                sum += 0*(i+1);
            else
                sum += (s[i]-'A'+1)*(i+1);
        }
        cout << sum << "\n";
    }

    return 0;
}
