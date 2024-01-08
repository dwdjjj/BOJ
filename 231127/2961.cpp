#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int ans = INT_MAX;
    vector<pair<int, int>> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 1; i < (1 << n); i++) { // n자리수 탐색
        int a = 1, b = 0;
        for (int x = 0; x < n; x++) {
            if(i & (1 << x)) { // 1이면 해당 재료 사용함
                a *= v[x].first;
                b += v[x].second;
            }
        }

        ans = min(ans, abs(a - b));
    }

    cout << ans;
    return 0;
}