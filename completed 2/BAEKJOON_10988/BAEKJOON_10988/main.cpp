#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string s;
    cin >> s;
    
    vector<char> tmp;
    tmp.clear();
    // tmp = reverse(s.begin(),s.end());
    
    for(int i=0; i<=s.size(); i++){
        tmp.push_back(s[s.size()-i-1]);
        // cout << tmp[i] << " " << s[i] <<"\n";
    }
    
    bool flag = true;
    for(int i=0; i<s.size(); i++){
        if(s[i]==tmp[i])
            flag = true;
        else
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << "1";
    else
        cout <<"0";
    
    return 0;
}
