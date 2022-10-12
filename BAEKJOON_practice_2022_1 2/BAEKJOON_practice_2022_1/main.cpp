#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s == "push") {
            int a;
            cin >> a;
            st.push(a);
        }
        if(s == "top"){
            if(!st.empty()) cout << st.top() << "\n";
            else cout << -1 << "\n";
        }
        if(s == "size"){
            cout << st.size() << "\n";
        }
        if(s == "empty"){
            if(st.empty()) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        if(s == "pop"){
            if(!st.empty()) {
                cout << st.top() << "\n";
                st.pop();
            }
            else cout << -1 << "\n";
        }
    }
    return 0;
}
