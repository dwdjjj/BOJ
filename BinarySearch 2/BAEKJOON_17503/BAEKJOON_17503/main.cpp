#include <vector>
#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int n, k;
ll m;
ll power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return power(x, n-1) * x;
}
vector<pair<int, int>> beer;
bool is_possible(ll mid) { // 맥주를 n개 전부 마시면서 mid로 간 레벨의 최솟값을 구하려 함.
    int cnt = 0; ll sum = 0;
    for (int i=k-1; i>=0; i--) {
        if (beer[i].second <= mid) {
            sum += beer[i].first;
            cnt++;
        }
        if (cnt == n) {
            break;
        }
    }
    if (m <= sum && cnt == n) {
        return true;
    }
    else return false;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    beer.resize(k);
    for (int i=0; i<k; i++) {
        cin >> beer[i].first >> beer[i].second; // first : 선호도, second : 도수 레벨
    }
    sort(beer.begin(), beer.end());
    
    ll left = 1, right = power(2, 31), ans = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (is_possible(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
    return 0;
}
