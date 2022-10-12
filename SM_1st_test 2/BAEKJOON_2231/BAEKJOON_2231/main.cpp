
#include <iostream>
using namespace std;
int n, sum, x;

int main(int argc, const char * argv[]) {
    cin >> n;
    
    for (int i=1; i<n; i++) {
        sum = i; x = i;
        
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        if (n == sum) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    
    
    return 0;
}
