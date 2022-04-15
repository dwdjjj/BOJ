#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int len, n, cnt = 0;
string s1;
string s2; // 반대로 도는 애
string res[105];
int main(int argc, const char * argv[]) {
    cin >> len;
    
    for (int i=0; i<len; i++) {
        char c; cin >> c;
        s1 += c;
        if (c == '1' || c == '2' ) s2 += c+2;
        if (c == '3' || c == '4' ) s2 += c-2;
    }
    reverse(s2.begin(), s2.end());

    cin >> n;
    
    while (n--) {
        string s;
        for (int i=0; i<len; i++) {
            char c; cin >> c;
            s+= c;
        }
        
        string tmp = s;
        
        for (int i=0; i<len; i++) {
            if (tmp == s1 || tmp == s2) {
                res[cnt] = s;
                cnt++;
                break;
            }
//            tmp = tmp.substr(1, tmp.length()) +tmp[0];
            
            tmp.push_back(tmp[0]);
            tmp.erase(0, 1);
//            cout << tmp << "\n";
        }
    }
    cout << cnt << "\n";
    
    for (int i=0; i<cnt; i++) {
        for (int j=0; j<len; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
