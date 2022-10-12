#include <vector>
#include <iostream>
using namespace std;
int n, m;
vector<int>v;
bool is_possible(int mid){
    int sum = 0, cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i]>mid) return false;
        if(sum<=mid){
            sum += v[i];
            if(sum>mid){
                cnt++;
                sum = v[i];
            }
        }
    }
    if(sum!=0) cnt++;
    if(cnt>m) return false;
    else return true;
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    int left = 1, right = 1e9, mid, ans=0;
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
