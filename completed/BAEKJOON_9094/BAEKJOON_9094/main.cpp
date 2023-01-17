#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N; cin >> M;
        
        int count = 0, tmp = 0;
        for(double a=1; a<N; a++){
            for(double b=a+1; b<N; b++){
                tmp = (a*a+b*b+M)/(a*b);
                if(tmp==(a*a+b*b+M)/(a*b))
                    count++;
            }
        }
        cout << count << "\n";
    }
    

    return 0;
}
