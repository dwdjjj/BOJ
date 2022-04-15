#include <iostream>
using namespace std;
int n, a, b, cnt = 0;
// 16 8 9 => 8->4->2 / 9->5->3
int main(int argc, const char * argv[]) { // a와 b가 붙게되는 라운드는?
    cin >> n >> a >> b;
    
    while(a!=b) {
        a = a/2 + a%2;
        b = b/2 + b%2;
        cnt++;
    }
    
    cout << cnt;
    return 0;
}
