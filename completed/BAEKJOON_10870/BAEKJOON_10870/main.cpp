#include <iostream>
using namespace std;
int n;
int f(int x){
    if(x==0) return 0;
    if(x==1) return 1;
    else return f(x-1)+f(x-2);
}
int main(int argc, const char * argv[]) {
    cin >> n;
    cout << f(n);
    return 0;
}
