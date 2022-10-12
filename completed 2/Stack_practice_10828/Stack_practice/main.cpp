//
//  main.cpp
//  Stack_practice
//
//  Created by 권영재 on 2021/05/11.
//
// #include <stack>
#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos++] = x;
}
void pop(){
    pos--;
}
int top(){
    return dat[pos-1];
}
void test(){
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    // stack<int> S;
    
    int N;
    cin >>N;
    while(N--){
        string s;
        cin >> s;
        if(s=="push")
        {
            int number;
            cin >> number;
            push(number);
        }
        else if(s=="pop")
        {
            if(pos==0)
                cout << -1 << "\n";
            else
            {
                cout << top() << "\n";
                pop();
            }
        }
        else if(s=="top")
        {
            if(pos==0)
                cout << -1 << "\n";
            else
                cout << top() << "\n";
        }
        else if(s=="size")
        {
            cout << pos << "\n";
        }
        else if(s=="empty")
        {
            if(pos==0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
    
    return 0;
}
