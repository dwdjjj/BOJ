#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 987654321;
int N, B, cnt = 0;
int heal[3001];
int cache[2][3001][3001];
// 상태공간정의 : 첫구간엔 피로회복못함(잠잘준비해야댐), B개의 구간만 잠을 자려함.
// 피로회복 최대로하려면?
int f(int flag, int a, int b)
{
    if (cnt == 0)
    {
        return -INF;
    }
    int &ret = cache[flag][a][b];
    if (ret != -1)
        return ret;

    return ret;
}
int main(int argc, const char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        cin >> heal[i];
    }

    return 0;
}
