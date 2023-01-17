#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    int N;
    cin >> N;
    cin.ignore();
    string s;
    int number=0;
    for(int i=0; i<N; i++)
    {
        getline(cin,s);
        number++;
        cout << number << ". " << s << "\n";
    }
    return 0;
}
