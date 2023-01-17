#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
vector<int>v; vector<int>vv;
bool is_possible(int mid){
    int len, x=0, cnt = 1;
    for(int i=1; i<n; i++){
        len = v[i]-v[x];
        if(len>=mid){
            x=i;
            cnt++;
        }
    }
    if(cnt>=m) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int left = 1, right = v[n-1]-v[0], ans = 1, mid;
    while(left<=right){
        mid = (left+right)/2;
        if(is_possible(mid)){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
