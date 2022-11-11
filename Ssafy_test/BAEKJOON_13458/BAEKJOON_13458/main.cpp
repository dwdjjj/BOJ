#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
vector<int> v;
ll ans;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    ll b, c;
    cin >> b >> c;
    
    for(int i=0; i<n; i++) {
        ans += 1; // 총감독 한명
        ll tmp = v[i] -= b; // 총감독이 맡을 학생 줄이고
        // 부감독 필요 인원 수
        if(tmp > 0) {
            if(tmp % c == 0) ans += tmp / c;
            else ans += tmp / c + 1;
        }
    }
    cout << ans;
    return 0;
}
