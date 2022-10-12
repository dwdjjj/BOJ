// 15732번 도토리 숨기기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
int n, k, d;
struct info {
    int start, end, len;
};
vector<info> box;

bool is_possible(int mid) {
    ll cnt = 0;
    for (int i=0; i<k; i++) {
        int s = box[i].start, e = box[i].end, l = box[i].len;
        // 시작박스, 끝박스, 간격
        
        if (s <= mid && mid <= e) { // 고른 박스가 시작점과 끝점 사이면
            cnt += (mid - s)/l + 1; // 고른박스에서 시작점까지 간격만큼 나눠 넣은 도토리 개수 셈.
        }
        if (e < mid) cnt += (e - s)/l + 1; // 고른 박스가 끝 이후면 시작에서 끝까지의 도토리 셈.
    }
    
    if (d <= cnt) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> d;
    
    for (int i=0; i<k; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        box.push_back({s, e, l});
    }
    
    int left = 1, right = n, ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (is_possible(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
    return 0;
}
