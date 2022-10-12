#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int r, c, num = 1;

vector<pair<int, int>> vp;
vector<pair<int, int>> res;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        string s; cin >> s;
        for (int j=0; j<s.size()-1; j++) {
            if ('1' <= s[j] && s[j] <= '9') {
                vp.push_back(make_pair(j, s[j]-'0'));
                break;
            }
        }
    }
    sort(vp.begin(), vp.end(), greater<>()); // 내림차순 정렬
    
    int check = vp[0].first;
    res.push_back(make_pair(vp[0].second, num));
    
    for (int i=1; i<vp.size(); i++) {
        if (check == vp[i].first) res.push_back(make_pair(vp[i].second, num));
        else {
            num++;
            res.push_back(make_pair(vp[i].second, num));
            check = vp[i].first;
        }
    }
    
    sort(res.begin(), res.end());
    
//    for (int i=0; i<vp.size()-1; i++) {
//        if (vp[i].second != c-1 || vp[i+1].second != c-1){
//            if (vp[i].second == vp[i+1].second) {
//                res.push_back(num);
//            }
//            else if (vp[i].second != vp[i+1].second) {
//                num++;
//                res.push_back(num);
//            }
//        }
////        cout << num << " ";
//    }

//    sort(vp.begin(), vp.end(), comparef);

    for (int i=0; i<res.size(); i++) {
        cout << res[i].second << "\n";
    }
    return 0;
}
