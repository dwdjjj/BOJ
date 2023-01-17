#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    int count=0;
    int tmp = N;
    while(tmp>0)
    {
        tmp = int(tmp/10); // 입력받은 수 N의 자릿수 count측정
        count++;
    }

    for(int i=1; i<count; i++)
    {
        N += 5*pow(10,i-1);
        N /= pow(10,i);
        N *= pow(10,i);
    }
    cout << N;
    
    return 0;
}
/* string N;
cin >> N;

for(int i=0; i<N.size(); i++)
{
    if((N[N.size()-i]-'0')>4){
        N[N.size()-i]='0';
        N[N.size()-i-1] -= '0'+1;
        if((N[0]-'0')>10)
        {
            // cout<< N[0];
        }
    }
    else
        N[N.size()-i]='0';

}
cout << N; */
