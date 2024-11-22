#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20000 + 2];
int visited[20000 + 2]; // 방문배열 색깔별(같은색 = 같은값)
int K, V, E;

// 1로 방문체크 -> 1로 체크되어있으면 idx번째는 2로 체크하기
void dfs(int start)
{
    if (!visited[start])
    {
        visited[start] = 1;
    }

    for (int i = 0; i < adj[start].size(); i++)
    {
        int idx = adj[start][i];
        if (!visited[idx])
        {
            if (visited[start] == 1)
                visited[idx] = 2;
            else if (visited[start] == 2)
                visited[idx] = 1;

            dfs(idx);
        }
    }
}

bool check()
{
    // 인접 노드와 색이 같다면 이분그래프가 아님!
    for (int i = 1; i <= V; i++)
    {
        // 자기자신만 연결된경우 반복문 안들어감
        for (int j = 0; j < adj[i].size(); j++)
        {
            int idx = adj[i][j];
            // 인접노드가 같은체크번호면 X
            if (visited[i] == visited[idx])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int u, v; // 연결된 노드 입력값

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
                dfs(i);
        }
        if (check() == 0)
            cout << "NO\n";

        else
            cout << "YES\n";

        memset(visited, 0, sizeof(visited));
        memset(adj, 0, sizeof(adj));
    }

    return 0;
}