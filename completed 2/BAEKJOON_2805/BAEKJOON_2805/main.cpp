#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
vector<int>v;
bool is_possible(int mid){
    ll sum = 0;
    for(int i=0; i<n; i++){
        if(v[i]>mid) sum += v[i]-mid;
    }
    if(sum>=m) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    int left=0, right = v[n-1], mid, ans = 0;
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
