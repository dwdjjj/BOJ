#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int n, a, b, MaxL = 0;
typedef long long ll;
vector<ll> x;
vector<ll> l;

bool is_possible(ll c){
    ll cur = x[0];
    for(int i=1; i<n; i++){
        if(cur + c > l[i]) return false;
        else {
            cur = max(x[i], cur+c);
        }
        
//        cout << cur << " ";
    }
//    cout << c << " ";
    return true;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        x.push_back(a);
        l.push_back(a+b);
        MaxL = max(MaxL, a+b);
    }
    sort(x.begin(), x.end());
    sort(l.begin(), l.end());
    ll left = 0, right = MaxL, mid, ans = 0;
    while(left<=right){
        mid = (left+right) / 2;
        if(is_possible(mid)){
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid-1;
        }
//        cout << "mid는" << mid << " ";
    }
    cout << ans;
    return 0;
}
