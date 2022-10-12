#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(vector<int>a, vector<int>b){
    return a[2]>b[2];
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    vector<vector<int>>x(n,vector<int>(3,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> x[i][j];
        }
    }
    
    sort(x.begin(), x.end(), compare);
    
    cout << x[0][0] << " " << x[0][1] << "\n"; // 금
    cout << x[1][0] << " " << x[1][1] << "\n"; // 은
    //동메달은 국가가 같은지 체크후 출력해야함..
    int count = 0;
    for(int i=0; i<n-1; i++){
        if(x[i][0]==x[i+1][0]){
            if(x[i+2][0]==x[i][0])
                count++;
        }
        else
        {
            break;
        }
            
    }
    cout << x[count+2][0] << " " << x[count+2][1];
    
    return 0;
}
