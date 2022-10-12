#include <stack>
#include <iostream>
using namespace std;
stack<int>s;
int k;
int main(int argc, const char * argv[]) {
    cin >> k;
    while(k--){
        int a; cin >> a;
        if(a==0) s.pop();
        else s.push(a);
    }
    int sum = 0;
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}
