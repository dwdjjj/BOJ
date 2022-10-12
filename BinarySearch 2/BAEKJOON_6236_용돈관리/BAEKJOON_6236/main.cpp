#include <vector>
#include <iostream>
using namespace std;
int n, m;
vector<int>v;
bool is_possible(int mid){
    int cur = mid, cnt = 1;
    for(int i=0; i<n; i++){
        if(mid < v[i]) return false;
        if(cur - v[i] < 0){
            cur = mid;
            cnt++;
        }
        cur -= v[i];
    }
    if(cnt<=m) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int sum = 0;
    for(int i=0; i<n; i++){
        int cost; cin >> cost;
        sum += cost;
        v.push_back(cost);
    }
    int left=1, right=sum, mid, ans = 0;
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
