#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX_N 50000+3
#define INF 987654321
using namespace std;
int n, m;
vector<pair<int, int>> adj[MAX_N];

vector<int> dijkstra() { // 1에서 스타트. n까지 가는 최소비용
    vector<int> d(n+1, INF);
    d[1] = 0;
    priority_queue<pair<int, int>> pq; // 현재헛간, 비용 pair로 넣기
    // 우선순위큐에서는 first가 우선 기준으로 내림차순으로 정렬되니까 비용을 first로 넣으면서 최소비용 찾는 듯?
    // 근데, first에 현재 헛간넣고, second로 비용넣어도 잘 됨. first가 같으면 second를 그 다음 기준으로 보니까?
// first헛간, second비용 넣고 top출력
//    4 -4      
//    4 -4
//    5 -7
//    5 -7
//    6 -8
//    4 -1
//    4 -1
//    5 -4
//    5 -4
//    6 -5
// first비용, second헛간 넣고 출력
//    -4 4
//    -1 2
//    -1 4
//    -1 4
//    -4 5
//    -4 5
//    -4 4
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < cost) continue;
        
        for (auto i : adj[now]) {
            int next = i.first, nextD = i.second + cost;
            if (nextD < d[next]) {
                d[next] = nextD;
                pq.push({-nextD, next});
//                cout << pq.top().first << " " << pq.top().second << "\n";
            }
        }
//        for (int i=0; i<adj[now].size(); i++) {
//            int next = adj[now][i].first, nextD = adj[now][i].second + cost;
//            if (nextD < d[next]) {
//                d[next] = nextD;
//                pq.push({next, -nextD});
//            }
//        }
    }
    
    return d;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); // a와 b헛간 사이의 c마리의 소 입력.
        adj[b].push_back({a, c});
    }
    vector<int> ans = dijkstra();
    
    cout << ans[n];
    return 0;
}
