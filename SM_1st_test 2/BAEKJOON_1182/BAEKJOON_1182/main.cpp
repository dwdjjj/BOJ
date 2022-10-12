#include <vector>
#include <iostream>
using namespace std;
int n, s, cnt = 0;
vector<int> v;
vector<int> res;
void dfs(int level) {
    
    if (level == n) {
        int sum = 0;
        for (int i=0; i<res.size(); i++) {// n을 v.size()로?
//            cout << res[i] << " ";
            sum += res[i];
            
        }
//        cout << sum << " ";
//        cout << "\n";
        
        if (sum == s) {
            cnt++;
        }
    }
    else {
        res.push_back(v[level]);
        dfs(level + 1);
        res.pop_back();
        dfs(level + 1);
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    dfs(0);
    if (s ==0) {
        cnt--;
    }
    cout << cnt;
    
    return 0;
}
