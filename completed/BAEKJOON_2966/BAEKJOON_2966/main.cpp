#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    string s;
    cin >> s;

    string Adrian = "ABC";
    string Bruno = "BABC";
    string Goran = "CCAABB";
    
    int A=0,B=0,G=0;
    int winner=0;
    for(int i=0; i<N; i++)
    {
        if(s[i]==Adrian[i%3])
            A++;
        if(s[i]==Bruno[i%4])
            B++;
        if(s[i]==Goran[i%6])
            G++;
    }
    if(A>B&&A>G)
    {
        winner = A;
        cout << winner << "\n";
        cout << "Adrian\n";
    }
    else if(B>A&&B>G)
    {
        winner = B;
        cout << winner << "\n";
        cout << "Bruno\n";
    }
    else if(G>A&&G>B)
    {
        winner = G;
        cout << winner << "\n";
        cout << "Goran\n";
    }
    else if(A==B&&B==G)
    {
        winner = A;// A=B=G
        cout << winner << "\n";
        cout << "Adrian\n";
        cout << "Bruno\n";
        cout << "Goran\n";
    }
    else{
        if(A==B)
        {
            winner = A;// A=B
            cout << winner << "\n";
            cout << "Adrian\n";
            cout << "Bruno\n";
        }
        if(B==G)
        {
            winner = B;// B=G
            cout << winner << "\n";
            cout << "Bruno\n";
            cout << "Goran\n";
        }
        if(G==A)
        {
            winner = G;// G=A
            cout << winner << "\n";
            cout << "Adrian\n";
            cout << "Goran\n";
        }
    }
    
    return 0;
}
