#include <vector>
#include <map>
#include <iostream>
using namespace std;
int n, cnt = 0;
vector<int> v;
map<double, int> first, second, third, fourth;
// gcd??
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        double x, y; cin >> x >> y;
        double m = y / x;
        
        if (0 < x && 0 <= y) first[m]++;
        if (x <= 0 && 0 < y) second[m]++;
        if (x < 0 && y <= 0) third[m]++;
        if (0 <= x && y < 0) fourth[m]++;
    }
    for (auto& i : first) {
        cnt = max(cnt, i.second);
    }
    for (auto& i : second) {
        cnt = max(cnt, i.second);
    }
    for (auto& i : third) {
        cnt = max(cnt, i.second);
    }
    for (auto& i : fourth) {
        cnt = max(cnt, i.second);
    }
//
//    for (auto iter = first.begin(); iter!=first.end(); iter++) {
//        cnt = max(cnt, iter->second);
//    }
//    for (auto iter = second.begin(); iter!=second.end(); iter++) {
//        cnt = max(cnt, iter->second);
//    }
//    for (auto iter = third.begin(); iter!=third.end(); iter++) {
//        cnt = max(cnt, iter->second);
//    }
//    for (auto iter = fourth.begin(); iter!=fourth.end(); iter++) {
//        cnt = max(cnt, iter->second);
//    }
//
    cout << cnt;
    return 0;
}
