#include <vector>
#include <iostream>
using namespace std;
const int MAX = 9;
vector<int>v;
int n, m;
//bool visited[MAX]={0,};
void f(int len){
    if(len==m){
        for(int i=0; i<m; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){
        /*if(!visited[i]){
            visited[i]=true;
            v.push_back(i);
            f(len+1);
            v.pop_back();
            visited[i]=false;
        }*/
        v.push_back(i);
        f(len+1);
        v.pop_back();
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    f(0);
    return 0;
}
