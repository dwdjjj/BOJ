#include <iostream>
#include <string>
using namespace std;
int L;
int main(int argc, const char * argv[]) {
    
    cin >> L;
    for(int i=1; i<=L; i++){
        int x, cnt = 0;
        cin >> x;
        string s, ans;
        cin >> s >> ans;
        
        for(int j=0; j<x; j++){
            if(s[j] != ans[j]) cnt++;
        }
        
        cout << "Case " << i << ": " << cnt << "\n";
    }
    return 0;
}
