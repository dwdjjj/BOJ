#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1000+4;
const int INF = 987654321;
int n, m, x, y;
vector<pair<int, int>> adj[MAX_N];
vector<int> dijkstra() {
    priority_queue<pair<int, int>> pq;
    vector<int> dis(n+1, INF);
    pq.push({0, y});
    dis[y] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first, now = pq.top().second;
        pq.pop();
        if (dis[now] < cost) continue;
        for (auto i : adj[now]) {
            int next = i.first, nextD = i.second + cost;
            if (nextD < dis[next]) {
                dis[next] = nextD;
                pq.push({-nextD, next});
            }
        }
    }
    return dis;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y;
    for (int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    vector<int> v = dijkstra();
//    for (auto &i : v){
//        cout << i << " ";
//    }
    vector<int> res;
    for (int i=0; i<n; i++) {
        if (v[i] == INF) {
            cout << -1;
            return 0;
        }
        res.push_back(v[i]);
    }
    sort(res.begin(), res.end());
    
//    for (auto &i : res){
//        cout << i << " ";
//    }
    int ans = 1, sum = 0;
    for (auto &i : res) {
        if (x < i) {
            cout << -1;
            return 0;
        }
        if (x < sum + i*2) {
            ans++;
            sum = 0;
        }
        sum += i*2;
    }
    
    cout << ans;
    return 0;
}

