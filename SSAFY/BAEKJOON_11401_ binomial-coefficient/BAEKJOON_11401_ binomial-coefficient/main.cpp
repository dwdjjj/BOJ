//
//  main.cpp
//  BAEKJOON_11401_ binomial-coefficient
//
//  Created by 권영재 on 2023/02/01.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long ll;
using namespace std;
const int mod = 10007;
int n, k;
int cache[1000+3][1000+3];
int f(int n, int k) {
    if(n == k) return 1;
    if(k == 0) return 1;
    
    int &ret = cache[n][k];
    if(ret != -1) return ret;
    
    ret = (f(n - 1, k - 1) + f(n - 1, k)) % mod;
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    cout << f(n, k);
    return 0;
}
