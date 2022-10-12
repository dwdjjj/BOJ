#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    int cnt = 1;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ',') {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
