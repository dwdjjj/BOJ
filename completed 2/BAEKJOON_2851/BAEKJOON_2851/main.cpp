
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int arr[10]={0,};
    int score[10]={0,};
    int sum = 0;
    for(int i=0; i<10; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        score[i] = sum;
    }
    
    int min = 100, idx = 0;
    for(int i=9; i>=0; i--){
        if(abs(score[i]-100)<min)
        {
            min = abs(score[i]-100);
            idx = i;
        }
    }
    cout << score[idx];
    return 0;
}
