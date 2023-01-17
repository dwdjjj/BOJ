#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int moveX[4]={1, 0, -1, 0}, moveY[4]={0, -1, 0, 1};
    int nowX=0, nowY=0;
    
    int N=0, D=0; //N은 방향을 바꾼 횟수, D:방향전환에 대한 값
    cin >> N;
    
    long long T[100000+3]={0,}; // T_i : i분간만큼의 거리, T_0을 0으로 두고, 이 때 속도는 1초당 1만큼 이동하는 속도
    int totalT; // T는 총 시간.
    cin >> totalT;
    
    for(int i=1; i<=N; i++)
    {
        string s;
        cin >> T[i] >> s;
        
        nowX += (T[i]-T[i-1]) * moveX[D];
        nowY += (T[i]-T[i-1]) * moveY[D];
        
        if(s=="right")
        {
            D = (D+1)%4;
        }
        else if(s=="left")
        {
            D = (D+3)%4;
        }
    }
    
    nowX += (totalT-T[N]) * moveX[D];
    nowY += (totalT-T[N]) * moveY[D];
    
    cout << nowX << " " << nowY ;
    return 0;
}
