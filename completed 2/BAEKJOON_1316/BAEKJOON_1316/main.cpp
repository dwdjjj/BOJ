#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    int count = 0;
    while(n--)
    {
        string s;
        cin >> s;
        // bool isVisited[26]={0,};
        

        bool check = true;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<i; j++){
                if(s[i]!=s[i-1]&&s[i]==s[j])
                {
                    check = false;
                    break;
                }
            }
        }
        if(check)
            count++;
    }
    cout << count;
    
    return 0;
}
