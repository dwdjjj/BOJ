//
//  main.cpp
//  BAEKJOON_20293
//  연료가 부족해
//  Created by 권영재 on 2022/06/15.
//
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 987654321;
int r, c, n;
int cache[3000+3];
struct info {
    int x, y, f;
};
vector<info> v;
//보관소 n개 중 idx번째의 x, y를 거칠지 말지. 거치면 f만큼 충전하고, 안거치면 다음 idx를 거칠지 말지 또 정하면서 소비할 연료의 최솟값 구하기.
int f(int idx) {
    // 기저
    if (idx == n+1) {
        return 0;
    }
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    int dx = v[idx+1].x - v[idx].x; // x 이동거리(소비 연료량)
    int dy = v[idx+1].y - v[idx].y; // y 이동
    if (dx < 0 || dy < 0) {
        ret= INF;
    }
    int tmp = dx + dy - v[idx+1].f; // 총 이동거리 - 충전된 연료.
    if (tmp < 0) tmp = 0;         // 충전량이 오바되면 음수니 0으로 바꿔줌.
    
    cout << v[idx+1].f << " " << tmp << "\n";
    
//    ret = INF;
    ret = min(v[idx+1].x + v[idx+1].y, f(idx+1) + tmp); // 안거치면 해당위치까지거리, 거치면 idx 1늘리고 연료충전.
    cout << ret << "\n";
    return ret;
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(cache, -1, sizeof(cache));
    cin >> r >> c >> n;
    
    v.push_back({1, 1, 0});
    for (int i=1; i<=n; i++) {
        int x, y, f;
        cin >> x >> y >> f;
        v.push_back({x, y, f});
    }
    v.push_back({r, c, 0});
    cout << f(0);
   
    return 0;
}
