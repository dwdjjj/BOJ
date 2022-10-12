#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    string k;
    cin >> k;
    int d = 0;
    bool flag = true;
    for(int i=0; i<k.size()-2; i++){
        if(k.size()==1){
            break;
        }
        d = k[i+1]-'0'-k[i]-'0';
        if(d==k[i+2]-'0'-k[i+1]-'0')
            flag = true;
        else
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    else
        cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
    return 0;
}
