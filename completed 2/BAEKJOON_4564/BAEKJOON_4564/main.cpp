//
//  main.cpp
//  BAEKJOON_4564
//
//  Created by 권영재 on 2021/05/04.
//

#include <iostream>
#include <string>
using namespace std;
//cout 띄어쓰기 다시한번 생각해보기 ㅇㅋ
int main(int argc, const char * argv[]) {
    
    do{
        string S;
        cin >> S;
        if(S=="0") break;
        cout << S << " ";
        
        while(S.size()>1){
            int tmp=1;
            
            for(int i=0; i<S.size(); i++){
                tmp *= S[i]-'0';
            }
            S = to_string(tmp);
            cout << tmp << " ";
        }
        
    }
    while(1);
    
    return 0;
}

