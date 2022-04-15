#include <iostream>
using namespace std;
int t;
int cache[11]; // DP
int f(int n) { // 1.상태공간정의 2.기저사례 3.점화식
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;
    
    int&ret = cache[n];
    if (ret != -1) return ret;

    if (n>3) {
        return ret = f(n-1) + f(n-2) + f(n-3);
    }
    
    return ret;
}
int main(int argc, const char * argv[]) {
    cin >> t;
    while (t--) {
        for (int i=0; i<11; i++) {
            cache[i] = -1;
        }
        int n; cin >> n;
        cout << f(n) << '\n';
    }
    return 0;
}
