//
//  main.cpp
//  BAEKJOON_1992_quadTree
//
//  Created by 권영재 on 2023/02/21.
//

#include <iostream>
using namespace std;
int n;
int arr[64][64];
void f(int y, int x, int size) {
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(arr[i][j] != arr[y][x]){
                cout << "(";
                int nextSize = size/2;
                f(y, x, nextSize);
                f(y, x+nextSize, nextSize);
                f(y+nextSize, x, nextSize);
                f(y+nextSize, x+nextSize, nextSize);
                cout << ")";
                return;
            }
        }
    }
    cout << arr[y][x];
}
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    f(0, 0, n);
    return 0;
}
