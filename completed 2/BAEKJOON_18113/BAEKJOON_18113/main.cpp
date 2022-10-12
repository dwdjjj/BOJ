#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n, k, m;
vector<int>v;
bool is_possible(int mid){
    int cnt = 0;
    for(int i=0; i<n; i++){
        cnt+=v[i]/mid;
        //cout << v[i] << " ";
    }
    if(cnt<m) return false;
    else return true;
}
int main(int argc, const char * argv[]) {
    cin >> n >> k >> m;
    int left=1, right, mid, ans=0;
    for(int i=0; i<n; i++){
        int a;
        cin >>a;
        v.push_back(a);
        if(v[i]<=k) v[i]=0;
        else if(v[i] < 2*k) v[i] -= k;
        else v[i] -= (2*k);
    }
    right = 1e9;
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
    if(ans==0) cout << -1;
    else cout << ans;
    return 0;
}
