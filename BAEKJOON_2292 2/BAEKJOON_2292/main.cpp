//
//  main.cpp
//  BAEKJOON_2292
//
//  Created by 권영재 on 2022/04/11.
//

#include <iostream>
using namespace std;

int n;
int main(int argc, const char * argv[]) {
    cin >> n;
    
    int x = 1, res = 1, i = 6;
    while (1) {
        if (n <= x) break;
        res++;
        x += i;
        i += 6;
    }
    cout << res;
    return 0;
}

