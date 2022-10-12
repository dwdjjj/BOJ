#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> adj;
// 고대어사전 알고리즘책2권
void makeGraph(const vector<string>& words){
    adj = vector<vector<int>>(26, vector<int>(26,0));
    
    for(int j = 1; j<words.size(); j++){
        int i = j-1, len = min(words[i].size(), words[j].size());
        
        for(int k = 0; k < len; k++){
            if(words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
        }
    }
}

int arr[100][100];
bool vis[100][100];
void bfs() {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>>q;
    q.push({0,0})
    vis[0][0] = 1;
    
    while (!q.empty()) {
        pair<int, int>cur = q.front(); q.pop();
        
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
