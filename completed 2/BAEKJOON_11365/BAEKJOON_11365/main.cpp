//
//  main.cpp
//  BAEKJOON_11365
//
//  Created by 권영재 on 2021/05/04.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
//주석처리로 문제는 맞았는데 reverse함수는 왜쓰면 안될까요?
    string S;
    do{
        getline(cin,S);
        if(S=="END") break;
        reverse(S.begin(),S.end());
        cout << S << "\n";
    }
    while(1);
    
    /*do{
        getline(cin,S);
        if(S=="END") break;
        char result[500] = {0,};
        for(int i=0; i<S.size(); i++){
            result[i]=S[S.size()-i-1];
        }
        for(int i=0; i<S.size(); i++){
            cout << result[i];
        }
        cout << "\n";
    }
    while(1);*/
    
    return 0;
}
