#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int m, S;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m;
    while (m--) {
        string str; cin >> str;
        int x;
        if (str == "add") {
            cin >> x;
            S |= (1<<x);
        }
        if (str == "check") {
            cin >> x;
            if (S & (1<<x)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        if (str == "remove") {
            cin >> x;
            S &= ~(1<<x);
        }
        if (str == "toggle") {
            cin >> x;
            S ^= (1<<x);
        }
        if (str == "all") {
            for (int i=1; i<=20; i++) {
                if (S & (1<<i)) continue;
                else S |= (1<<i);
            }
        }
        if (str == "empty") {
            for (int i=1; i<=20; i++) {
                if (S & (1<<i)) S &= ~(1<<i);
            }
        }
    }
    return 0;
}
