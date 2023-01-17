#include <queue>
#include <string>
#include <iostream>
using namespace std;
queue<int> q;
int n, x;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s=="push"){
            cin >> x;
            q.push(x);
        }
        else if(s=="pop"){
            if(q.size()==0) cout << "-1\n";
            else{
                x=q.front();
                q.pop();
                cout << x << "\n";
            }
        }
        else if(s=="size"){
            cout << q.size() << "\n";
        }
        else if(s=="empty"){
            cout << q.empty() << "\n";
        }
        else if(s=="front"){
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if(s=="back"){
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}
