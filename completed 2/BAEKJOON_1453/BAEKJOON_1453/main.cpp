
#include <iostream>

using namespace std;
//pc방자리
int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    int PC[100]={0,};
    
    int n, count=0;
    for(int i=0; i<N; i++)
    {
        cin >> n;
        for(int i=0; i<100; i++)
        {
            if(i==(n-1))
                PC[i]++;
        }

    }
    for(int i=0; i<100; i++)
    {
        if(PC[i]>1)
            count+=PC[i]-1;
    }
    cout << count;
    
    return 0;
}
