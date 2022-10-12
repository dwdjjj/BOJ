    #include <vector>
    #include <queue>
    #include <iostream>
    #include <cstring>
    const int MAX = 50;
    using namespace std;
    int adj[MAX][MAX];
    bool vis[MAX][MAX];
    int w, h, cnt = 0;
    int dw[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    int dh[8] = {1, 0, -1, 0, -1, 1, 1, -1};

    void bfs(int h, int w){
        queue<pair<int, int>>q;
        q.push(make_pair(h, w));
        vis[h][w] = true;
        
        while(!q.empty()){
            h = q.front().first;
            w = q.front().second;
            q.pop();
            
            for(int i=0; i<8; i++){
                int nh = h + dh[i];
                int nw = w + dw[i];
                
                if(0<=nw && 0<=nh && nw<MAX && nh<MAX){
                    if(adj[nh][nw] && !vis[nh][nw]){
                        vis[nh][nw] = true;
                        q.push(make_pair(nh, nw));
                    }
                }
            }
        }
    }

    void dfs(int h, int w){
        vis[h][w] = true;
        for(int i=0; i<8; i++){
            int nh = h + dh[i];
            int nw = w + dw[i];
            
            if(0<= nw && 0<=nh && nw<MAX && nh<MAX){
                if(adj[nh][nw]&&!vis[nh][nw]){
                    vis[nh][nw] = true;
                    dfs(nh, nw);
                }
            }
        }
        
    }
    int main(int argc, const char * argv[]) {
        while(1){
            cin >> w >> h;
            if(w==0 && h==0) break;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    cin >> adj[i][j];
                }
            }
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(adj[i][j]&&!vis[i][j]){
                        cnt++;
                        //bfs(i, j);
                        dfs(i, j);
                    }
                }
            }
            cout << cnt << "\n";
            cnt = 0;
            memset(adj, 0, sizeof(adj));
            memset(vis, 0, sizeof(vis));
        }
        
        return 0;
    }
