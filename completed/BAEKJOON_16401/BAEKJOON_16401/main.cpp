#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int m, n;
vector<int>v;
bool is_possible(int mid){
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i]/mid>0) {
            cnt+=v[i]/mid;
        }
    }
    if(cnt>=m) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<n; i++){
        int snack; cin >> snack;
        v.push_back(snack);
    }
    sort(v.begin(), v.end());
    int left = 1, right = v[n-1], mid, ans = 0;
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
