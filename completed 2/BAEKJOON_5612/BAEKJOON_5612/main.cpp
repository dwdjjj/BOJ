
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int N;
    cin >> N; // 조사한 시간 입력
    int M;
    cin >> M; // 안에 있던 차량 수
    int err=0,max = 0;
    while(N--){
        int in, out;
        cin >> in;
        cin >> out;
        M += in;
        M -= out;
        if(M<0) err--;
        if(M>max) max = M;
    }
    if(err<0) cout << 0;
    else cout << max;
    
    return 0;
}
