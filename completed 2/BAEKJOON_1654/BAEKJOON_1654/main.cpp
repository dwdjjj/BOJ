#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;
int k, n;
vector<int>v;
bool is_possible(ll mid){
    int cnt = 0;
    for(int i=0; i<k; i++){
        cnt += v[i]/mid;
    }
    if(cnt>=n) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i=0; i<k; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    ll left=1, right=v[k-1], mid, ans = 0;
    while(left<=right){
        mid = (left+right)/2;
        if(is_possible(mid)){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    cout << ans;
    return 0;
}
