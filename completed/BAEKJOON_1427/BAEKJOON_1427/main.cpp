#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool compare(char a, char b){
    if(a!=b)
        return a>b;
    else
        return a>b;
}

int main(int argc, const char * argv[]) {
    string N;
    cin >> N;
    
    sort(N.begin(),N.end(),compare);
    
    cout << N;
    
    return 0;
}
