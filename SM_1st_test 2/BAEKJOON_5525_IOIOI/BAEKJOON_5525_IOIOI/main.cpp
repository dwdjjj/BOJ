#include <string>
#include <iostream>
using namespace std;
int n, m, ans = 0;
bool visited[1000004];
string s, p = "I";
//int f(int idx, int length) {
//    int cnt = 0;
//    if (idx > length-1) {
//        return 0;
//    }
//    string tmp = s.substr(idx, 1+n*2);
//    if (tmp == p) {
//        cnt++;
//    }
//    return cnt;
//}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> s;
//    for (int i=0; i<n; i++) {
//        p += "OI";
//    }
    for (int i = 0; i < m; i++) {
        int len = 0; // len는 IOI...의 길이
        if (s[i] == 'I') {
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                len++;
                if (len == n)
                {
                    len--;
                    ans++;
                }
                i += 2;
            }
            len = 0;
        }
    }
    cout << ans;

return 0;
}
