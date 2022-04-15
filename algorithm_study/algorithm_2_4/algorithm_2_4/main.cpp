#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 1000+3;
int n, m, v;
vector<int> adj[MAX];
vector<bool> visited(MAX, false);

void bfs(int u) {
    visited[u] = true;
    queue<int> q;
    q.push(u);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";
    for (int i=0; i<adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> n >> m >> v;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(v);
    
    fill(visited.begin(), visited.end(), false);
    cout << "\n";
    
    bfs(v);
    
    return 0;
}
