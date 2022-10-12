#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int N, M, C;
vector<int> cow;
bool is_possible(int mid) {
    int bus_cnt = 1, last = cow[0], idx = 0;
    for (int i=1; i<cow.size(); i++) {
        if (cow[i] - last <= mid && i + 1 - idx <= C) continue;
        else {
            bus_cnt++;
            last = cow[i];
            idx = i;
        }
    }
    if (bus_cnt <= M) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> C;
    cow.resize(N);
    for (int i=0; i<N; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());
    int left = 0, right = cow[N-1], ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
//        cout << mid << " ";
        if (is_possible(mid)) {
            right = mid - 1;
            ans = mid;
        }
        else left = mid + 1;
    }
    cout << ans;
    return 0;
}
