#include <iostream>
//#include <vector>
using namespace std;

//A팀이 역전패를 하면 Yes출력하기
int main(int argc, const char * argv[]) {
    int A[9], B[9];
    int sumA=0, sumB=0;
    bool win = false, flag = false;
    for (int i=0; i<9; i++) {
        int a;
        cin >> a;
        A[i] = a;
    }
    for (int i=0; i<9; i++) {
        int b;
        cin >> b;
        B[i] = b;
    }
    for (int i=0; i<9; i++) {
        sumA += A[i];
        
        if(sumA > sumB){
            win = true; //A가 이기고 있을 때 true로
        }
        
        sumB += B[i];
        if(sumA < sumB && win==true){
            flag = true;
            break;
        }
    }
    cout << (flag ? "Yes" : "No");
    return 0;
}
