#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n, m;
vector<int>v;
bool is_possible(int mid){
    ll cnt=0;
    for(int i=0; i<m; i++){
        cnt += v[i]/mid+1;
        if(v[i]%mid==0) cnt--;
    }
    if(cnt>n) return false;
    else return true;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int left, right, mid, ans=0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    left = 1; right = v[m-1];
    while(left<=right){
        mid = (left+right)/2;
        if(is_possible(mid)){
            ans = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    cout << ans;
    return 0;
}
