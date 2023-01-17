#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    while(1){
        string s;
        getline(cin,s);
        
        if(s=="*") break;
        
        bool isVisited[26]={0,};

        for(int i=0; i<s.size(); i++){
            if('a'<=s[i]&&s[i]<='z')
                isVisited[s[i]-'a']=true;
        }
        
        int count = 0; // 여기 bool로 못푸려나??
        for(int i=0; i<26; i++)
        {
            if(isVisited[i])
                count++;
        }
        
        if(count==26)
        {
            cout << "Y\n";
        }
        else cout << "N\n";
    }
    
    return 0;
}
