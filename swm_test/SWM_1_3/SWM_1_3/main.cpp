// 3번 : 암호메시지 복호화
#include <iostream>
#include <string> // 3 복호화
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int a, b;
vector<char> ans;
vector<int> res;
int main() {
    cin >> a >> b;
    string s;
    cin >> s;
    // a = 0, b =1, ... z= 25
    // g = 6,u, o, e = 4
    // for (int i=0; i<s.length(); i++) {
    //     int tmp = s[i]- 'a';
    //     int tmp2 = (tmp - b) / a;
    //     ans.push_back(tmp2 + 'a');
    // }
    for(int i=0; i<s.length(); i++) {
        for(int j=0; j<26; j++) {
            if((j*a + b)%26 == s[i] - 'a') {
                ans.push_back(j + 'a');
                break;
          }
        }
    }
    // for(int i=0; i<res.size(); i++) {
    //     cout << res[i];
    // }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}
