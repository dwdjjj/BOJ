#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m, L;
vector<int>v;
bool is_possible(int mid){
    int len, cnt=0;
    for(int i=1; i<v.size(); ++i){
        len = v[i]-v[i-1];
//        if(len/mid>0){
//            if(len%mid==0){
//                cnt += (len/mid)-1;
//            }
//            else{
//                cnt += (len/mid);
//            }
//        }
        cnt += len/mid;
        if(len%mid==0) {
            cnt--;
        }
        //cout << cnt << ", ";
    }
    if(cnt<=m) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> L;
    v.push_back(0);
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    v.push_back(L);
    sort(v.begin(), v.end());
    int left = 1, right = L, mid, ans = 0;
    // left 를 0으로 잡으니 division by zero 에러남
    while(left<=right){
        mid = (left+right)/2;
        //cout << mid << " ";
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
