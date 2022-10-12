#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int MAX_N = 20000 + 2;
const int INF = 987654321;
int v, e, k; // 정점개수 v, 간선개수 e, 시작 정점 번호 k
vector<pair<int, int>> adj[MAX_N];

//vector<int> dijkstra() {
//    vector<int> dis(v + 1, INF);
//    dis[k] = 0;
//    priority_queue<pair<int, int>> pq;
//    pq.push({0, k});
//
//    while (!pq.empty()) {
//        int cost = -pq.top().first;
//        int now = pq.top().second;
//        pq.pop();
//        if (dis[now] < cost) continue;
//
//        for (auto i:adj[now]) {
//            int next = i.first, nextD = i.second + cost;
//            if (nextD < dis[next]) {
//                dis[next] = nextD;
//                pq.push({-nextD, next});
//            }
//        }
//    }
//    return dis;
//}

vector<int> dijkstra() {
    vector<int> dis(v+1, INF);
    dis[k] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dis[now] < cost) continue;

        for (int i=0; i<adj[now].size(); i++) {
            int next = adj[now][i].first, nextD = adj[now][i].second + cost;
            if (nextD < dis[next]) {
                dis[next] = nextD;
                pq.push({-nextD, next});
            }
        }
    }
    return dis;
}

int main(int argc, const char * argv[]) {
    cin >> v >> e >> k;
    for (int i=0; i<e; i++) { // u-v간선의 가중치 w
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> ans = dijkstra();
    for (int i=1; i<=v; i++) {
        if (ans[i] != INF) cout << ans[i] << "\n";
        else cout << "INF\n";
    }
    return 0;
}
