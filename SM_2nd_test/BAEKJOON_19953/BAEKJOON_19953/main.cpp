
#include <iostream>
using namespace std;
int iv, m, t;
int v[4];
int cnt[4]; // 0 : 동쪽, 1: 아래, 2: 서쪽, 3: 북쪽
int main(int argc, const char * argv[]) {
    cin >> iv >> m >> t;
    
    // 1초꺼 이동
    int x = 0, y = iv;
    t--;
    int tmp = (iv * m) % 10; // 초기속도인 iv에 m곱해주고 10으로 나눈 나머지 저장.
    for (int i=0; i<4; i++) {
        v[i] = tmp;
        tmp = (tmp * m) % 10;
    }
    
    for (int i = 0; i < 4; i++) {
        cnt[i] = (t-1) / 4;
    }
    
    for (int i=0; i<= (t - 1) % 4; i++) {
        cnt[i]++;
    }
    x += v[0] * cnt[0] - v[2] * cnt[2];
    y += v[3] * cnt[3] - v[1] * cnt[1];
    cout << x << " " << y;
    return 0;
}
