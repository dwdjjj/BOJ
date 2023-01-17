#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = 100+2;
const int MAX_W = 100000+1;
int n, k;
vector<pair<int, int>> v;
vector<bool> visited;
int cache[MAX_N][MAX_W];
// 상태공간 정의 : k무게만큼까지 버틸 수 있는만큼 물건들을 집어 넣는데, 가치가 최대가 되도록 집어 넣음.
// idx번째 물건을 보고 넣을지 말지 선택.
int f(int idx, int weight) {
    if(idx >= n) return 0;
    
    int& ret = cache[idx][weight];
    if(ret != -1) return ret;
    
    if(weight + v[idx].first > k) return f(idx + 1, weight);
    
    return ret = max(f(idx + 1, weight + v[idx].first) + v[idx].second, f(idx + 1, weight));
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(cache, -1, sizeof(cache));
    visited.resize(n+1);
    cin >> n >> k;
    v.resize(n+1);
    for(int i=0; i<n; i++) { // first : 무게, second : 가치
        cin >> v[i].first >> v[i].second;
    }
    
    cout << f(0, 0);
    return 0;
}
