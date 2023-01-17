#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 101;
const int MAX_K = 10001;
int cache[MAX_N][MAX_K], cost[MAX_N];
int N, K; // 동전 종류가 n개, 총합 k원 되도록 / 다만 여러 동전의 액수가 서로 배수관계가 아니면 그리디로 풀 수 없음!

//따라서 DP로 푼다.
int f(int n, int k){
    if(n == N) return 0;
    if(k == 0) return 0;
    if(n == N && k > 0) return -1;
    
    if(cache[n][k] != -1) return cache[n][k];
    
    int res = f(n+1, k);
    return res;
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> K;
    
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<N; i++){
        cin >> cost[i];
    }
    return 0;
}
