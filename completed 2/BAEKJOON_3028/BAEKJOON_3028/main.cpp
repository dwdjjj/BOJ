//
//  main.cpp
//  BAEKJOON_3028
//
//  Created by 권영재 on 2021/05/04.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int cup[3]={1, 0, 0};
    string S;
    cin >> S;
    int tmp = 0, check=0;
    for(int i=0; i<S.size(); i++){
        if(S[i]=='A'){
            tmp = cup[0];
            cup[0]=cup[1];
            cup[1] = tmp;
            
        }
        else if(S[i]=='B'){
            tmp = cup[1];
            cup[1]=cup[2];
            cup[2]=tmp;
        }
        else if(S[i]=='C'){
            tmp = cup[0];
            cup[0]=cup[2];
            cup[2]=tmp;
        }
    }
    for(int i=0; i<3; i++){
        if(cup[i]==1) check=i+1;
    }
    cout << check;
    return 0;
}
