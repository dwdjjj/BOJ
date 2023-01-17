
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, sum=0;
    int arr[9]={0,};
    for(int i=0; i<9; i++){
        cin >> n;
        arr[i] = n;
        sum += n;
    }
    int fake1=0, fake2=0;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(100 == sum - arr[i] - arr[j]){
                fake1 = i; fake2 = j;
            }
        }
    }
    for(int i=0; i<9; i++){
        if(i!=fake1 && i!=fake2)
            cout << arr[i] << "\n";
    }
    
    return 0;
}
