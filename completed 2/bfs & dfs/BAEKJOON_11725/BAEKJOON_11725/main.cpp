#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int MAX = 100001;
int N;
//vector<int> adj[MAX];
vector<vector<int>> adj;
vector<int> parent(MAX);
vector<bool> visited(MAX, false);
void bfs(){
    queue<int>q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<adj[cur].size(); i++){
            int next = adj[cur][i];
            if(!visited[next]){
                parent[next] = cur;
                q.push(next);
                visited[next] = true;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    adj.resize(N+1);
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    
    for(int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }
    return 0;
}
