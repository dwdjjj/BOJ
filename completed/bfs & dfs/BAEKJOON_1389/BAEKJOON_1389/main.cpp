#include <queue>
#include <vector>
#include <iostream>
#define MAXSIZE 101
using namespace std;
int n, m, ans=0, MIN = 1e9;
vector<int> adj[101];
int visited[101]; // -1로 방문하지 않게 초기화해두고 start부터 거쳐간 거리 저장해 res에 계속 더해줌
void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int bfs(int start){
    
    queue<int>q;
    q.push(start);
    visited[start] = 0;
    int res = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        res += visited[cur];
        for(int next:adj[cur]){
            if(visited[next] == -1){
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }
    return res;
}
/*class Graph{
public:
    int N; // 정점 개수
    vector<vector<int>>adj;
    
    Graph():N(1){}
    Graph(int n):N(n){adj.resize(N);}
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void sortList(){
        for(int i=0; i<N; i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }
    
    void bfs(int start){
        
        queue<int>q;
        q.push(start);
        visited[start] = 1;
        
        while(!q.empty()){
            start = q.front();
            q.pop();
            for(int i=1; i<=n; i++){
                if(adj[start][i]==1 && visited[i]==0){
                    visited[i] = visited[start] + 1;
                    q.push(i);
                }
            }
        }
    }
};*/
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    // Graph G(n);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        addEdge(a, b);
        addEdge(b, a);
    }
    
    for(int i=1; i<=n; i++){ // 1에서 n까지 bfs돌려서 최솟값일때의 숫자 ans에 저장
        memset(visited, -1, sizeof(int)*MAXSIZE);
        int res = bfs(i);
        if(res < MIN){
            MIN = res;
            ans = i;
        }
    }
    cout << ans;
    
    return 0;
}
