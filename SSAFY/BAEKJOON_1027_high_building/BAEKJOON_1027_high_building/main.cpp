#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>
using namespace std;

int n;
vector<int> h;
int cnt[50+3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        h.push_back(x);
    }
    for(int i=0; i<n; i++) {
        double MAX_Inc = -1000000000;
        for(int j=i+1; j<n; j++) {
            if(i == j) continue;
            int dh = h[j] - h[i];
            int dx = j - i;
            double inc = (double)dh / dx;
            if(inc > MAX_Inc) {
                MAX_Inc = inc;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(cnt[i], ans);
//        cout << cnt[i] << " ";
    }
    cout << ans;
    return 0;
}
