#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n, x, y, m;
vector<int>adj[101];
int d[101];
vector<bool>visited;

int bfs(int start, int end){
    queue<int>q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==end) return d[end];
        
        for(int i=0; i<adj[cur].size(); i++){
            int next = adj[cur][i];
            if(!visited[next]){
                if(!d[next]){
                    q.push(next);
                    d[next] = d[cur]+1;
                }
            }
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    cin >> x >> y;
    cin >> m;
    for(int i=0; i<m; i++){
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    visited = vector<bool>(n+1, false);
    
    cout << bfs(x, y);
    
    return 0;
}
