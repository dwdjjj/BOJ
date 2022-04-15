#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m, cnt = 0;
map<string, int> mp;
vector<string> res;
//vector<string>v1;
//vector<string>v2;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n+m; i++) {
        string x;   cin >> x;
        mp[x]++;
        if (mp[x] > 1) res.push_back(x);
    }
    
    sort(res.begin(), res.end());
    
//    for (int i=0; i<n; i++) {
//        for (int j=0; j<m; j++) {
//            if (v1[i] == v2[j]) {
//                res.push_back(v1[i]);
//            }
//        }
//    }
    cout << res.size() << "\n";
    
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << "\n";
    }
    return 0;
}
