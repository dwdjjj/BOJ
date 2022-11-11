#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
vector<int> ans;
bool visited[10];

void f(int idx, int cnt)
{
    v.resize(10);
    ans.resize(10);
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && v[i] != last)
        {
            last = v[i];
            ans[cnt] = v[i];
            visited[i] = true;
            f(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(int argc, const char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    f(0, 0);

    return 0;
}
