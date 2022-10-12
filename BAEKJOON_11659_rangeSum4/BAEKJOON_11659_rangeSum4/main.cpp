#include <vector>
#include <iostream>
using namespace std;
int n, m, sum = 0;
vector<int> v;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    v.resize(n+1);
    fill(v.begin(), v.end(), 0);
    for (int i=1; i<=n; i++) {
        int tmp; cin >> tmp;
        sum += tmp;
        v[i] = sum;
    }
    for (int i=0; i<m; i++) {
        int x, y, ans = 0;
        cin >> x >> y;
        ans = v[y] - v[x-1];
        cout << ans << "\n";
    }
    return 0;
}
