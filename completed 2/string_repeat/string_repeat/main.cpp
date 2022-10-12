#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
/*    bool visited[26]={0,};
    int tmp[100]={0,};
    
    for (int i=0; i<S.size(); i++){
        visited[S[i]-'a']=true;
        if(visited[i]) tmp[i]=i;
    }
    //처음등장하는위치, 아니면 -1출력
    for (int j=0; j<26; j++){
        if(visited[j]){
            cout << tmp[j] << " ";
        }
        else cout << -1 << " ";
        
    }*/
    
    string S;
    cin >> S;
    char alphabet[]="abcdefghijklmnopqrstuvwxyz";
    int key=0;
    for(int i=0; i<26; i++){
        for(int j=0; j<S.size(); j++){
            if(alphabet[i]==S[j]){
                cout << j << " ";
                key=0;
                break;
            }
            else key=1;
        }
        if(key==1) cout << -1 << " ";
    }

    return 0;
}
