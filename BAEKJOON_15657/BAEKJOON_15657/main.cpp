#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
vector<int> v;
vector<int> res;

void f(int idx, int cnt) {
    if (cnt == m) {
        for (int i=0; i<m; i++) {
            cout << res[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i=idx; i<n; i++) {
        res.push_back(v[i]);
        f(i, cnt+1);
        res.pop_back();
    }
    return;
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    f(0, 0);
    return 0;
}
