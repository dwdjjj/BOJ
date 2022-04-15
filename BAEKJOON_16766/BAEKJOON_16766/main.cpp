#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c;
vector<int>v;
bool is_possible(int mid){
    int waitT, x=0, cow_cnt = 0, bus_cnt=0;
    for(int i=0; i<v.size(); i++){
        waitT = v[x+1] - v[x];
        if(waitT<=mid){
            cow_cnt++;
            x++;
        }
        if(cow_cnt==c){
            bus_cnt++;
            cow_cnt = 0;
            x=i;
        }
    }
    cout << bus_cnt << ", ";
    if(bus_cnt>=m) return true;
    else return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c;
    for(int i=0; i<n; i++){
        int time; cin >> time;
        v.push_back(time);
    }
    sort(v.begin(), v.end());
    int left=0, right=1e9, mid, ans=0;
    while(left<=right){
        mid = (left+right)/2;
        cout << mid << " ";
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
