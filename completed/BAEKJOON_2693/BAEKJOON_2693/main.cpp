#include <vector>
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    while(n--){
        vector<int>A(10,0);
        
        for(int i=0; i<10; i++){
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        
        cout << A[7] <<"\n";
        
    }
    
    return 0;
}
