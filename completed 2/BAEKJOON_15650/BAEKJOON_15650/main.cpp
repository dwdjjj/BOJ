#include <vector>
#include <iostream>
using namespace std;
const int MAX = 8+1;
int n, m;
vector<int>v;
int arr[MAX]={0,};
bool visited[MAX]={0,};
void f(int x, int len){
    // m=1 : 1,2,3,... n
    // m=2 : 1,2 1,3 1,4 2,3 2,4 3,4
    if(len==m){
        for(int i=0; i<m; i++){
            cout << v[i] << " ";
            // cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=x; i<=n; i++){
        if(!visited[i]){
            visited[i]=true;
            // arr[len] = i;
            v.push_back(i);
            f(i+1,len+1);
            v.pop_back();
            visited[i]=false;
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    f(1, 0);
    return 0;
}
