#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    double a, b, c;
    for(a=6; a<=100; a++)
    {
        for(b=2; b<=100; b++)
        {
            for(c=b+1; c<=100; c++)
            {
                for(double d=c+1; d<=100; d++)
                {
                    if(a*a*a == b*b*b + c*c*c + d*d*d)
                    {
                        cout << "Cube = " << a;
                        cout << ", Triple = ("<<b<<","<<c<<","<<d<<")\n";
                    }
                }
            }
        }
    }
    

    return 0;
}
