#include <vector>
#include <algorithm>
#include <iostream>
#define MAX_N 1000000+4
typedef long long ll;
using namespace std;
int n, q;
bool visR[MAX_N] = {false, };
bool visC[MAX_N] = {false, };
             
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    ll sumR = 0, sumC = 0, cntR = 0, cntC = 0;
    for (int i=1; i<=q; i++) {
        char Querytype; int num;
        cin >> Querytype >> num;
        ll ans = num * n + ((n * (n + 1)) / 2);
        
        if (Querytype == 'R') {
            if (visR[num]) cout << 0 << "\n";
            else {
                cout << ans - sumC - cntC * num << "\n";
                cntR++;
                sumR += num;
                visR[num] = true;
            }
        }
        if (Querytype == 'C') {
            if (visC[num]) cout << 0 << "\n";
            else {
                cout << ans - sumR - cntR * num << "\n";
                cntC++;
                sumC += num;
                visC[num] = true;
            }
        }
    }
    
    // 21 22 23 = 3 4 5 => 12
    // 21 22 23 24 = 3 4 5 6 => 18
    // 외않뒈
    return 0;
}
