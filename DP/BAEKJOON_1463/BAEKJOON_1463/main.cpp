
#include <iostream>
using namespace std;
const int MAX = 1e6+3;

int cache[MAX];

int f(int x) {
    if(x==1) return 0;
    if(cache[x] != -1) return cache[x];
    
    int res = f(x-1) + 1;
    if(x%2 == 0) res = min(res, f(x/2) + 1);
    if(x%3 == 0) res = min(res, f(x/3) + 1);
    cache[x] = res;
    return res;
}

int main(int argc, const char * argv[]) {
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}
