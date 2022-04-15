#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(1){
        int x;
        cin >> x;
        if(x == 0) break;
        
        string s;
        cin >> s;
        int y = int(s.length()) / x, row = 0;
        char arr[203][203] = {' ',}; 
//        cout << x << " " << y <<"\n";
        
//        vector<vector<char>> v;
//        for(int i=0; i<s.length(); i++){
//            if(i%x==0 && i != 0) row++;
//            if(row % 2 == 0) v[i % x].push_back(s[i]);
//            else v[x - (i % x) - 1].push_back(s[i]);
//        }
//        for(int i=0; i<x; i++){
//            for(int j=0; j<v[i].size(); j++){
//                cout << v[i][j];
//            }
//        }
        
        for(int i=0; i<y; i++){
            
            if(i%2 == 1) { //홀수행
                for(int j=0; j<x; j++){
                    arr[i][x - j - 1] = s[i * x + j];
                }
            }
            
            if(i%2 == 0) { //짝수행
                for(int j=0; j<x; j++){
                    arr[i][j] = s[i * x + j];
                }
            }
        }
        
        for(int j=0; j<x; j++){
            for(int i=0; i<y; i++){
                cout << arr[i][j];
            }
        }
        cout << "\n";
        
    }
    return 0;
}
