#include <bits/stdc++.h>

using namespace std;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,
        M;

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    // 1~100 숫자중에 가장 큰 수이자 공통값이면 ans에 저장 후 그 뒤의 idx부터 계속 탐색
    int aIdx = 0;
    int bIdx = 0;
    for (int x = 100; x > 0; x--)
    {
        for (int i = aIdx; i < N; i++)
        {
            if (A[i] == x)
            {
                for (int j = bIdx; j < M; j++)
                {
                    if (B[j] == x)
                    {
                        ans.push_back(x);
                        aIdx = i + 1;
                        bIdx = j + 1;

                        break;
                    }
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}