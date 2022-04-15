#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n, m, e, len = 987654321;
vector<int> v;

int main(int argc, const char * argv[]) {
    cin >> n >> m >> e;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(e);
    sort(v.begin(), v.end());
    
    for (int i=0; i<n+1-m; i++) {
        len = min(v[i+m]-v[i], len);
    }
    cout << len;
    return 0;
}
//6 3 7
//2 4 5 8 11 12
