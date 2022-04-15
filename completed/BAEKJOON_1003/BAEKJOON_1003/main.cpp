
#include <iostream>
using namespace std;

int cache[40+3];

int f(int n){
    if(n==0) {
        cache[0] = 0;
        return 0;
    }
    if(n==1) {
        cache[1] = 1;
        return 1;
    }
    if(cache[n]!=0) return cache[n];
    else return cache[n] = f(n-1) + f(n-2);
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n==0) cout << "1 0\n";
        else if(n==1) cout << "0 1\n";
        else {
            f(n);
            cout << cache[n-1] << " " << cache[n] << "\n";
        }
    }
    
    
    return 0;
}
