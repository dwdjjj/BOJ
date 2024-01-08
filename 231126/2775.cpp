#include <iostream>
int apt[15][15];
using namespace std;

int main()
{
    // 0층 - i호 - i명 / 1, 2, 3, 4, 5 ...
    // 1층 - i호 - 1, 3, 6, 10, 15 ... 
    // 2층 - 1, 4, 10, 20, 35, ...
    // a층 - b호 -> (a-1)층의 1~b호까지의 합
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int k, n;
        cin >> k >> n;
        // 0층 초기화
        for (int j = 0; j <= 15; j++) {
            apt[0][j] = j;
        }

        for (int y = 1; y <= k; y++) {
            for (int x = 1; x <= n; x++) {
                if(apt[y][x])
                    continue;

                for (int k = 1; k <= x; k++) {
                    apt[y][x] += apt[y - 1][k];
                }
            }
        }
        cout << apt[k][n] << "\n";
    }
}