#include <iostream>
#include <string>
using namespace std;
int T;
char c = '0';
int main(int argc, const char * argv[]) {
    // 홀수번째는 그대로 짝수번째는 두배로 만들고 10이상이면 각자리수 합으로 대체해 모든 자리수 합이 10으로 나뉘면 유효.
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int sum = 0;
        for(int i=15; i>=0; i--){
            if(i % 2 == 0){
                int tmp = (s[i] - c) * 2;
                if(tmp >= 10){
                    int a = (tmp % 10) + (tmp / 10);
                    sum += a;
                }
                else sum += tmp;
            }
            else {
                int b = s[i] - c;
                sum += b;
            }
        }
        if(sum % 10 == 0) cout << "T\n";
        else cout << "F\n";
        
    }
    return 0;
}

