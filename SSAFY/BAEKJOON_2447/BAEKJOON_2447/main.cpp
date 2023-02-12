#include <iostream>
using namespace std;
int n;
int arr[6600][6600];

void f(int i, int j, int n) {
    if(n == 0) {
        cout << "*";
        return;
    }
    if((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << " ";
    }
    else {
        f(i, j, n/3);
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            f(i, j, n);
        }
        cout << "\n";
    }
    return 0;
}
