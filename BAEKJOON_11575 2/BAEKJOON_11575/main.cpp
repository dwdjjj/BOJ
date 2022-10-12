#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int t;
int main() {
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s, ans;
        cin >> s;
        vector<int> v;
        v.resize(26);
        for (int i=0; i<26; i++) {
            v[i] = (a * i + b) % 26 + 'A';
        }
        for (int i=0; i<s.length(); i++) {
            s[i] = v[s[i] - 'A'];
        }
        cout << s << "\n";
        
//        vector<int> v;
//        v.resize(s.size());
//        for (int i=0; i<s.size(); i++) {
//            v[i] = (a * (s[i] - 'A') + b) % 26;
//            cout << v[i] << " ";
//            ans[i] = v[i] + 'A';
//        }
//
//        cout << ans << "\n";
    }
    return 0;
}
