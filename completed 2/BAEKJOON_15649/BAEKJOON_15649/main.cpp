#include <vector>
#include <iostream>
using namespace std;
const int MAX = 9;
int N, M;
bool visited[MAX] = {0,};
vector<int>v;

void f(int cnt){
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i]=true;
            v.push_back(i);
            f(cnt+1);
            v.pop_back();
            visited[i]=false;
        }
    }
    
}
int main(int argc, const char * argv[]) {
    cin >> N >> M;
    f(0);
    return 0;
}
