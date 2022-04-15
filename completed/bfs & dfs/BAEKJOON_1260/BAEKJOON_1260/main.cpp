#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1000+2;
int n, m, start; // n:정점 m:간선
vector<int> adj[N];
vector<bool> visited_d(N, false);
vector<bool> visited_b(N, false);

/*void addedge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}*/
void dfs(int cur){
    visited_d[cur] = true;
    cout << cur << " ";
    /*for(int next: adj[cur]){
        if(!visited[next]) dfs(next);
    }*/
    for(int i=0; i<adj[cur].size(); i++){
        int next = adj[cur][i];
        if(!visited_d[next]) dfs(next);
    }
}
void bfs(int start){
    queue<int>q;
    q.push(start);
    visited_b[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        /*for(int next: adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }*/
        for(int i=0; i<adj[cur].size(); i++){
            int next = adj[cur][i];
            if(!visited_b[next]){
                q.push(next);
                visited_b[next] = true;
            }
            
        }
    }
}
int main(int argc, const char * argv[]) {
    cin >> n >> m >> start;
    // adj[1][2]=1;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        //addedge(a, b);
    }
    
    //오름차순으로 정렬(번호 작은거부터 먼저 방문해야되서)
    for(int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(start);
    cout << "\n";
    bfs(start);

    return 0;
}
