#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int President[n+1];
        int sum=0, max=0, winner=0;
        bool draw = true;
        for(int i=1; i<=n; i++)
        {
            cin >> President[i];
            sum+=President[i];
            if(max < President[i])
            {
                max=President[i];
                winner = i;
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(President[i]==max && i!=winner){
                draw = false;
            }
        }
        
        if(draw)
        {
            if(sum/2 < max)
                cout << "majority winner " << winner <<"\n";
            else
                cout << "minority winner " << winner << "\n";
        }
        else
            cout << "no winner\n";
    }
    
    return 0;
}
