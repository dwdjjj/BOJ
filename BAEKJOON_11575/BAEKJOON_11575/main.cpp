#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }

    int ans = 0;
    int noop;

    // 벌 - 꿀 - 벌
    for (int i = 1; i < n; i++) {
        noop = v[i];
        ans = max(ans, total - v[0] - v[n - 1] + noop);
    }

    // 벌 - 벌 - 꿀
    noop = v[n - 1];
    for (int i = n - 2; i > 0; i--) {
        ans = max(ans, total - v[0] - v[i] + noop);
        noop += v[i];
    }

    // 꿀 - 벌 - 벌
    noop = v[0];
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, total - v[n - 1] - v[i] + noop);
        noop += v[i];
    }

    cout << ans << '\n';
}
