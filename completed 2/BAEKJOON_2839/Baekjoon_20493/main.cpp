
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){

    int N;
    cin >> N;
    int i, j, min=5000, tmp=0;
    for(i=0; i<=N/3; i++){
        for(j=0; j<=N/5; j++){
            if((i*3+j*5)==N){
                tmp = i+j;
                if(tmp<min) min = tmp;
            }
        }
    }
    if(min==5000||min==0) cout << -1;
    else cout << min;
    /*int tmp1 = 0,tmp2=0, min1 = 0, min2=0, min=0;
    
    tmp1 = N%5; tmp2 = N%3;
    min1 = N/5; min2 = N/3;
    if(tmp1==0){
        min = min1;
    }
    if(tmp2==0){
        if(tmp1==0) min = min1;
        else if(tmp1==3) min = min1+1;
        else min = min2;
    }
    if(tmp1!=0&&tmp2!=0){
        if(tmp1==3) min = min1+1;
        else if((3+tmp2)==5) min = min2;
        else if((tmp1)%3==0) min = min1+(tmp1)/3;
        // else cout << -1;
    }
    if(min!=0) cout << min;
    else cout << -1;*/
    return 0;
}
