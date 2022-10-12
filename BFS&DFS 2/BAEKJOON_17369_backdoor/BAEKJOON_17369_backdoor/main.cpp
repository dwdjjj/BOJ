#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX_N = 300000+2;
const ll INF = MAX_N * 100000;
vector<bool> eyesight;
vector<pair<int, ll>> adj[MAX_N];
ll n, m;
vector<ll> dijkstra() {
    priority_queue<pair<ll, int>> pq;
    vector<ll> dis(n+1, INF);
    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll cost = -pq.top().first;
        int now = pq.top().second;
        
        pq.pop();
        if (dis[now] < cost) continue;
        for (int i=0; i<adj[now].size(); i++) {
            int next = adj[now][i].first; ll nextT = adj[now][i].second + cost;
            if (nextT < dis[next]) {
                dis[next] = nextT;
                pq.push({-nextT, next});
            
            }
        }
    }
    return dis;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x; cin >> x; eyesight.push_back(x);
    }
    eyesight.pop_back(); eyesight.push_back(0); // 마지막 분기점은 어차피 보일테고, 보이면서 갈 수 있음
    for (int i=0; i<m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        if(eyesight[a] || eyesight[b]) continue;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    vector<ll> ans = dijkstra();
//    for (int i=1; i<n; i++) {
//        cout << ans[i]<< " ";
//    }
    if (ans[n-1] == INF) cout << "-1";
    else cout << ans[n-1];
    return 0;
}
