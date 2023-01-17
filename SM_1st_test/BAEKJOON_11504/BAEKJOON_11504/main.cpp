#include <string>
#include <iostream>
using namespace std;
int t, n, m;

int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        string x;
        string y;
        string wheel;
        int cnt = 0;
        cin >> n >> m;
        for (int i=0; i<m; i++) {
            char a; cin >> a;
            x += a;
        }
        for (int i=0; i<m; i++) {
            char a; cin >> a;
            y += a;
        }
        for (int i=0; i<n; i++) {
            char a; cin >> a;
            wheel += a;
        }
        for (int i=0; i<n; i++) {
            string tmp = "";
            for (int j=0; j<m; j++) {
                if (n-1 < j+i) tmp += wheel[(j+i)%n];
                else tmp += wheel[j+i];
            }
            if (x <= tmp && tmp <= y) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
