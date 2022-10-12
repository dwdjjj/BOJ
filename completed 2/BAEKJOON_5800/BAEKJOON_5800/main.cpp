#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int k, X=1; // k : 반의 수, X : 반의 번호
    cin >> k;
    while(k--){
        int n, max=0, min=100, gap=0, tmp=0;
        cin >> n;
        vector<int>math(n,0);
        
        for(int i=0; i<n; i++){
            cin >> math[i];
        }
        sort(math.begin(),math.end());
        for(int i=0; i<n-1; i++){
            tmp = math[i+1] - math[i];
            if(tmp > gap)
                gap = tmp;
        }
        max = math[n-1]; min = math[0];
        
        cout << "Class " << X << "\n";
        cout << "Max " << max << ", Min " << min << ", Largest gap " << gap <<"\n";
        X++;
    }
    
    return 0;
}
