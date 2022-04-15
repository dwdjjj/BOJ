#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, ans = 987654321;
vector<int> v;
int main(int argc, const char * argv[]) {
    cin >> n;
    v.resize(2*n);
    for (int i=0; i<2*n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    for (int i=0; i<n; i++) {
        ans = min(ans, v[i] + v[2*n-1-i]);
    }
    cout << ans;
    return 0;
}
