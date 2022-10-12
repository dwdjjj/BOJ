#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int d, n, m;
vector<int>v{0, };
bool is_possible(int mid){
    int cnt = 0, x = 0;
    for(int i=1; i<=n+1; i++){
        if(v[i]-v[x] < mid) cnt++;
        else x = i;
    }
    if(cnt <= m) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> n >> m;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    v.push_back(d);
    sort(v.begin(), v.end());
    
    int left=0, right=d, mid, ans=0;
    while(left<=right){
        mid = (left+right)/2;
        // cout << mid << " ";
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
