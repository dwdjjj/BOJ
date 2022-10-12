#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 5000 + 3;
int n, m;
int arr[MAX_N]; // 각 쉼터의 높이 저장 배열
int cache[MAX_N];
vector<int> adj[MAX_N];
int f(int idx) {
//    if (idx == n) {
//        return 1;
//    }
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    ret = 1;
    for (int i=0; i<adj[idx].size(); i++) {
        ret = max(ret, f(adj[idx][i])+1);
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        if (arr[x] < arr[y]) adj[x].push_back(y);
        else adj[y].push_back(x);
    }
    memset(cache, -1, sizeof(cache));
    for (int i=1; i<=n; i++) {
        cout << f(i) << "\n";
    }
    return 0;
}
