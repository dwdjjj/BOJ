#include <string>
#include <iostream>
typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
    while (1) {
        ll n; cin >> n;
        int cnt = 1;
        if (n == 0) break;
        cin.ignore();
        for (int i=0; i<n; i++) {
            bool flag = false;
            string s; getline(cin, s);
            for (int j=cnt-1; j<s.length(); j++) {
                if (s[j] == ' ' && cnt <= j + 1) {
                    cnt = j + 1;
                    flag = true;
                    break;
                }
            }
            if (!flag && cnt < s.length() + 1) {
                cnt = s.length() + 1;
            }
            
        }
        
//        for (int i=0; i<n; i++) {
//            string s; getline(cin, s);
//            while (ans <= s.length()) {
//                if (s[ans-1] == ' ') break;
//                ans++;
//            }
//        }
        cout << cnt << "\n";
    }
    
    return 0;
}
