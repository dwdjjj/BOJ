#include <vector>
#include <iostream>
using namespace std;
int n, a, b, ans;
bool flag = false;
vector<int> v;

//void f(vector<int> &v) {
//    for (int i=0; i<n-1; i++) {
//        for (int j=-n; j<n; j++) {
//            for (int k=-n; k<n; k++) {
//                if(v[i+1] == v[i] * j + k) {
//                    a = j; b = k;
//                }
//            }
//        }
//    }
//}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    
    if (n <= 2) {
        if(n == 1) cout << 'A';
        else if (v[0] == v[1]) cout << v[0];
        else cout << 'A';
    }
    if (n > 2) {
        int d1 = v[1] - v[0];
        int d2 = v[2] - v[1];
        if(d1 != 0) a = d2/d1;
        int b = v[1] - a * v[0];
//        if(v[3] == v[2] * a + b) flag = true;
        for (int i=n-1; i>0; i--) {
            if(v[i] == v[i-1] * a + b) flag = true;
            else {
                flag = false;
                break;
            }
        }
        if(flag) ans = v[n-1] * a + b;
        else {
            cout << "B";
            return 0;
        }
        cout << ans;
    }
//    f(v);
//    cout << a << " " << b;
    return 0;
}
