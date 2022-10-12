#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    
    string A, B;
    cin >> A >> B;
    int length;
    if(A.size()>B.size())
        length = (signed)A.size(); // 노란줄 뜨긴하는데.. 못없애나?
    else
        length = (signed)B.size();
    
    vector<int>x(length,0);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for(int i=0; i<length; i++){
        if('0'>A[i]||A[i]>'9')
            x[i] = B[i]-'0';
        else if('0'>B[i]||B[i]>'9')
            x[i] = A[i]-'0';
        else
            x[i] = A[i]-'0'+B[i]-'0';
    }
    reverse(x.begin(), x.end());
    for(int i=0; i<x.size(); i++){
        cout<<x[i];
    }
    return 0;
}
