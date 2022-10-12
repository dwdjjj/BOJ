#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 200+3;
const int INF = 987654321;
int n, k;
int cache[MAX_N][MAX_N][MAX_N];
int arr[MAX_N][2];
// 상태공간 : idx번째 줄에 왼쪽을 닫을지 오른쪽을 닫을지, 이전 방 정보에 따라, k개까지 닫아 열려있는 가치총합이 최대가 되도록 함. last: 왼쪽닫음 = 0 / 오른쪽닫음 = 1 / 아무방도안닫음 = 2
int f(int idx, int last, int cnt) {
    if (cnt == 0) {
        int sum = 0;
        for (int i=idx; i<n; i++) {
            for (int j=0; j<2; j++) {
                sum += arr[i][j];
            }
        }
        return sum;
    }
    if (n == idx && 0 < cnt) return -INF;
    
    int& ret = cache[idx][last][cnt];
    if (ret != -1) return ret;
    ret = -INF;
    
    if (last != 1) ret = max(ret, f(idx + 1, 0, cnt-1) + arr[idx][1]);
    if (last != 0) ret = max(ret, f(idx + 1, 1, cnt-1) + arr[idx][0]);
    ret = max(ret, f(idx + 1, 2, cnt) + arr[idx][0] + arr[idx][1]);
    
    return ret;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++) {
            cin >> arr[i][j];
        }
    }
    cout << f(0, 2, k);
    return 0;
}
