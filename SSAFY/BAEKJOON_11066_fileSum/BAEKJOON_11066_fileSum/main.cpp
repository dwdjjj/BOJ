//
//  main.cpp
//  BAEKJOON_11066_fileSum
//
//  Created by 권영재 on 2023/02/26.
//

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
const int MAX_K = 500+3;
const int MAXVAL = 987654321;
int t, k, ans;
int files[MAX_K];
int cumSum[MAX_K];
int cache[MAX_K][MAX_K]; // i ~ j 구간의 최소 합

// 두 파일의 합치는 것을 i~j까지의 합으로
int f(int start, int end) {
    if(start == end) return 0;
    
    int& ret = cache[start][end];
    if(ret != -1) return ret;
    
    ret = MAXVAL;
    
    int tmpSum = cumSum[end] - cumSum[start - 1];
    
    for(int i = start; i < end; i++) {
        ret = min(ret, f(start, i) + f(i + 1, end) + tmpSum);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        ans = MAXVAL;
        
        cin >> k;
        for(int i = 1; i <= k; i++) {
            cin >> files[i];
            cumSum[i] += cumSum[i-1] + files[i];
        }

        ans = f(1, k); // 1base
        cout << ans << "\n";
    }
    return 0;
}
