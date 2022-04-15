#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321, MAX_V = 5000+3;
int v, e, p;
vector<pair<int, int>> adj[MAX_V];
// 최단거리까지의 경로에 p로 입력받은 건우의 위치를 지나치는지 확인하기 == 1~건우까지 건우~v까지 최단거리 합이 1~v까지의 최단거리와 같으면 SAVE HIM출력!
// first에 비용, second에 현재 위치 넣는 pair 우선순위큐
int dijkstra(int start, int end) {
    priority_queue<pair<int, int>> pq;
    vector<int> dis(v+1, INF);
    pq.push({0, start}); // start에서 시작, end까지 갈거임
    dis[start] = 0;
    
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        int cost = -cur.first, now = cur.second;
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
    return dis[end];
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> p;
    for (int i=0; i<e; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    if (dijkstra(1, v) == dijkstra(1, p) + dijkstra(p, v)) cout << "SAVE HIM";
    else cout << "GOOD BYE";
    return 0;
}
