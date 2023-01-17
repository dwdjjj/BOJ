#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, ans = 1;
vector<int> v;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    
//    multiset<int> box;
//    for(int i=0; i<n; i++) {
//        int x; cin >> x; box.insert(x);
//    }
//    for(int i : box) {
//        ans = max(ans, (int)box.count(i));
//    }
    
    for(int i=0; i<n; i++) {
        int x; cin >> x; v.push_back(x);
    }
        
    int cnt = 1;
    sort(v.begin(), v.end());
    for(int i=0; i< v.size(); i++) {
        if(v[i] == v[i+1]) {
            cnt+=1;
            ans = max(ans, cnt);
        }
        else cnt = 1;
    }
    
    cout << ans;
    return 0;
}
