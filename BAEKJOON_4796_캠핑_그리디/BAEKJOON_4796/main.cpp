#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int cnt = 0;
    while(1){
        int L, P, V;
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0) break;
        
        int Q = V/P, R = V%P;
        
        if(R<L) R = V%P;
        else R = L;
        
        int ans = Q*L + R;
        cnt++;
        cout << "Case " << cnt << ": " << ans << "\n";
        
    }
    
    return 0;
}
