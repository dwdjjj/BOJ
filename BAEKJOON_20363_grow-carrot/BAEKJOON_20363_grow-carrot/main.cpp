#include <iostream>
#include <algorithm>
using namespace std;

int x, y, ans = 0, tmp = 0;

int main(int argc, const char * argv[]) {
    cin >> x >> y;
    if(x > y) {
        ans = x + y + (y/10);
    }
    else {
        ans = x + y + (x/10);
    }
    
    cout << ans;
    return 0;
}
