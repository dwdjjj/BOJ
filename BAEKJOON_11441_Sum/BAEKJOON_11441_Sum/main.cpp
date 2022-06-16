#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n; // n : 수의 개수
    v.resize(n+1);
    fill(v.begin(), v.end(), 0);
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v[i+1] = v[i] + x;
    }
    
    cin >> m; // m : 구간의 개수
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        cout << v[y] - v[x-1] << "\n";
    }
    return 0;
}
