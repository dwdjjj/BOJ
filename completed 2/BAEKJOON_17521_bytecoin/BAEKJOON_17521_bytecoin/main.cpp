#include <iostream>
using namespace std;
typedef long long ll;
ll n, w, cnt;
ll arr[15+2];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w;
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    for (int i=0; i<n; i++) {
        if (i == n-1) {
            w += arr[i] * cnt;
            cout << w;
        }
        if (arr[i] < arr[i+1]) { // 다음날의 가격이 더비싸면 풀매수
            ll tmp = w / arr[i];
            cnt += tmp;
            w -= tmp * arr[i];
        }
        else if (arr[i] > arr[i+1]) {
            w += arr[i] * cnt;
            cnt = 0;
        }
    }
    
    return 0;
}
