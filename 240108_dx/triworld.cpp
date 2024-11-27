#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
int T;
int num[10001];

// an = (n^2 - n + 2) / 2
// n = ( 1 + root(8an - 7) ) / 2
int an(int n) {
    return (n * n - n + 2) / 2;
}
int f(int an) {
    return (1 + sqrt(8 * an - 7)) / 2;
}

int main()
{

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int s, e, ans = 0;
        cin >> s >> e;
        int startN, endN, maxN, minN, startX, endX, tmpX;
        startN = f(s);
        endN = f(e);
        minN = min(startN, endN);
        maxN = max(startN, endN);
        int verticalN = maxN - minN; // 세로로 몇칸 이동해야하는지.    
        startX = s - an(startN);    
        endX = e - an(endN);
        if(s > e) {
            tmpX = startX;
        }
        else if(e > s) {
            tmpX = endX;
        }
        else {
            ans = 0;
        }


        // if(s > e) {
        //     tmpX = startN - 1;
            // startX = startN - 1;
            // endX = e - an(endN);
        // }
        // else if(s < e) {
        //     tmpX = endN - 1;
            // endX = endN - 1;
            // startX = s - an(startN);
        // }
        printf("%d\n", tmpN);
        printf("%d\n", tmpX);
        
        ans = verticalN + tmpN - 1;

        cout << "#" << i << " " << ans << "\n";
    }
    

    return 0;
}