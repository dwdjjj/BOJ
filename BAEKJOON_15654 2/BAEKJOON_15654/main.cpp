#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 10;
bool visited[MAX] = {0,};
int n, m;
vector<int>v; vector<int>res;
//int arr[MAX] = {0,}; int res[MAX] = {0,};
void f(int len){
    if(len==m){
        for(int i=0; i<m; i++)
            cout << res[i] << " ";
            //cout << res[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i]=true;
            res.push_back(v[i]);
            //res[len] = arr[i];
            f(len+1);
            res.pop_back();
            visited[i]=false;
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        v.push_back(number);
        //arr[i] = number;
    }
    sort(v.begin(),v.end());
    f(0);
    return 0;
}
