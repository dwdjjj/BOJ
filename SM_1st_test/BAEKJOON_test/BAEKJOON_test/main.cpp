#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int n;
stack<int>s;
queue<int>q;
int arr[1002]={0,};
int res[1002]={0,};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        q.push(a);
    }
    int cnt = 1;
    while(!q.empty()){
        int now = q.front();
        if(now==cnt) {
            q.pop();
            cnt++;
        }
        else {
            if(!s.empty()&&s.top()==cnt){
                s.pop();
                cnt++;
            }
            else{
                s.push(now);
                q.pop();
            }
        }
    }
    while(!s.empty()){
        int now = s.top();
        s.pop();
        if(now!=cnt){
            cout << "Sad";
            return 0;
        }
        cnt++;
    }
    cout << "Nice";
    return 0;
}

