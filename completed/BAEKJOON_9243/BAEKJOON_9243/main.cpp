
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    
    string file, ans;
    cin >> file >> ans;

    while(N--){
        for(int i=0; i<file.size(); i++)
        {
            if(file[i]=='1')
                file[i]='0';
            else if(file[i]=='0')
                file[i]='1';
        }
        
    }
    bool flag = true;
    for(int i=0; i<file.size(); i++){
        if(file[i]!=ans[i])
        {
            flag = false;
            break;
        }
        else if(file[i]==ans[i])
        {
            flag = true;
        }
    }
    if(flag)
        cout << "Deletion succeeded";
    else
        cout << "Deletion failed";

    return 0;
}
