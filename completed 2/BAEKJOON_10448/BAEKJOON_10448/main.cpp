
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    while(n--){
        
        int K;
        cin >> K;
        int arr[45+1];
        int sum=0;
        for(int i=1; i<=45; i++){
            sum += i;
            arr[i] = sum;
        }
        bool flag = false;
        for(int i=1; i<=45; i++){
            for(int j=1; j<=45; j++){
                for(int k=1; k<=45; k++){
                    if(K==arr[i]+arr[j]+arr[k])
                    {
                        flag = true;
                    }
                }
            }
        }
        if(flag)
            cout << "1\n";
        else
            cout << "0\n";
    }
    
    return 0;
}
