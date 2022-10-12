#include <vector>
#include <iostream>
using namespace std;
int n;
vector<int> v;
int main(int argc, const char * argv[]) {
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    int ans = 0, cnt = 0, tmp = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] > tmp) {
            tmp = v[i];
            cnt = 0;
        }
        else cnt++;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
