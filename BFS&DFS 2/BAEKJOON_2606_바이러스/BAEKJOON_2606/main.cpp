#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n, m;
vector<int> adj[101];
bool visited[101] = {false};
int cnt = 0;

void dfs(int cur){
    visited[cur] = true;
    for(int next=0; next < adj[cur].size(); next++)
        if(!visited[adj[cur][next]]){
            visited[adj[cur][next]] = true;
            dfs(next);
        }
}

queue<int>q;
void bfs(){
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cnt++;
        for(int next: adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //dfs(1);
    bfs();
    cnt-=1; //시작부분 제외
    cout << cnt;
    return 0;
}
