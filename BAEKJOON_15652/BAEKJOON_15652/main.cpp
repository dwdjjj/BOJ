#include <vector>
#include <iostream>
using namespace std;
const int MAX = 9;
vector<int>v;
int n, m;
void f(int x,int len){
    if(len==m){
        for(int i=0; i<m; i++)
            cout << v[i] << " ";
        cout << '\n';
        return;
    }
    for(int i=x; i<=n; i++){
        v.push_back(i);
        f(i,len+1);
        v.pop_back();
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    f(1,0);
    return 0;
}
