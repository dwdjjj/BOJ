#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
const int MAX_N = 1000+4;
const int INF = 987654321;
int n;
vector<int> v;
int cache[MAX_N];
// 상태공간정의 : idx부터 다음학생까지를 보면서 최대최소값은 갱신하고, 그 학생까지 조로 포함시켜가며 얻는 점수의 최대
int f(int idx){
    if (n <= idx) return 0;
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    int maxS = 0, minS = INF;
    for (int i=idx; i<n; i++) {
        maxS = max(v[i], maxS);
        minS = min(v[i], minS);
        ret = max(ret, f(i+1) + maxS - minS);
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    cout << f(0);
    return 0;
}
