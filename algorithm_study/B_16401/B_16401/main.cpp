#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> v;
int m, n;

bool is_possible(int a) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += v[i] / a;
    }
    return cnt >= m;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    int left = 1, right = v.back(), ans = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_possible(mid)) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;

    }
    cout << ans;
    return 0;
}
