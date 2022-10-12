#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 987654321;
const int MAX_N = 50+3;
const int MAX_M = 1000+3;
int n, s, m;
int cache[MAX_N][MAX_M];
vector<int> v;
// idx번째의 볼륨을 더할지 말지 정하여 마지막 연주시 0보다 크거나 같고 m보다 작거나 같은 볼륨 중 최댓값.
int f(int idx, int sum) {
    if (n == idx && 0 <= sum && sum <= m) {
        return sum;
    }
    if (m < sum || sum < 0) {
        return -INF;
    }
    
    int& ret = cache[idx][sum];
    if (ret != -1) return ret;
   
    return ret = max(f(idx + 1, sum + v[idx]), f(idx + 1, sum - v[idx]));
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> s >> m;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    if (f(0, s) == -INF) {
        cout << -1;
    }
    else cout << f(0, s);
    return 0;
}
