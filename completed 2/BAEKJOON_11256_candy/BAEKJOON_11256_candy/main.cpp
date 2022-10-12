#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
vector<int> v;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        v.clear();
        int J, N; cin >> J >> N;
        int cnt = 0;
        for(int i=0; i<N; i++) {
            int r, c; cin >> r >> c;
            int size = r * c;
            v.push_back(size);
        }
        sort(v.begin(), v.end());
        
        for(int i=N-1; i>=0; i--) {
            if(J <= v[i]) {
                cnt++; break;
            }
            else {
                J -= v[i];
                cnt++;
                
            }
        }
        cout << cnt << "\n";
    }
    
    
    return 0;
}
