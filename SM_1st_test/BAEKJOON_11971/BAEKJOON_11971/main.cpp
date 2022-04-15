#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> lim;
vector<int> run;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int d, v;
        cin >> d >> v;
        for (int j=0; j<d; j++) {
            lim.push_back(v);
        }
    }
    for (int i=0; i<m; i++) {
        int d, v;
        cin >> d >> v;
        for (int j=0; j<d; j++) {
            run.push_back(v);
        }
    }
    
    int ans = 0;
    for (int i=0; i<100; i++) {
        ans = max(ans, run[i] - lim[i]);
    }
    
    cout << ans;
    return 0;
}
