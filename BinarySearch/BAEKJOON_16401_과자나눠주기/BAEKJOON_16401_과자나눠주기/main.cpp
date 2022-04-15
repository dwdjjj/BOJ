#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int m, n;
vector<int> v;
bool is_possible(int mid) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += v[i] / mid;
    }
    if (cnt >= m) {
        return true;
    }
    else return false;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int left = 1, right = v[v.size()-1], mid, ans = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (is_possible(mid)) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ans;
    return 0;
}
