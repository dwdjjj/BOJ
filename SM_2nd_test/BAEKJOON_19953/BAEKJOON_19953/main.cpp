
#include <iostream>
using namespace std;
int iv, m, t, nx = 0, ny = 0, d = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(int argc, const char * argv[]) {
    cin >> iv >> m >> t;
    int v = iv;
    for (int i=1; i<=t; i++) {
        nx += v * dx[d];
        ny += v * dy[d];
        v = (v * m) % 10;
        d = (d+1)%4;
    }
    cout << nx << " " << ny;
    return 0;
}
