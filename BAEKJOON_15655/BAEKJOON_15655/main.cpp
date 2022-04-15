#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 10;
bool visited[MAX]={0, };
int n, m;
vector<int>v; vector<int>res;
void f(int x, int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=x; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            res.push_back(v[i]);
            f(i, cnt+1);
            visited[i]=false;
            res.pop_back();
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    f(0, 0);
    return 0;
}
