#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

typedef long long ll;
using namespace std;
int T;
bool isPrime(ll x) {
    if(x <= 1)
        return false;

    for (int i = 2; i <= sqrt(x); i++) 
    {
        if (x % i == 0) return false;
    }

    return true;
}

int main()
{

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        ll n;
        cin >> n;

        while(!isPrime(n))
            n++;

        cout << n << "\n";
    }
    

    return 0;
}