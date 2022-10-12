#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>
using namespace std;
const int MAX_N = 1000+4;
const int MAX_M = 16+2;
const int INF = 987654321;
int arr[MAX_N][MAX_M];
int ans[MAX_N][MAX_M];
int cache[MAX_N][2][MAX_M];
int leave = 0;
bool flag = true;
int N, M, K; // N손님, M현재메뉴개수, K없애려는 메뉴 개수
// j번 메뉴를 버릴지 말지 정해서 이탈하는 손님 제외 나머지가 남음
// 선호도가 5이상인 메뉴가 최소 1개는 있는지 확인하고 (j번메뉴를 버려도 5이상인 메뉴가 전부 사라지는지 아닌지 체크)
// 총 K개의 메뉴를 버리고 유지할 수 있는 손님의 최대수 구하기

// 즉, j번메뉴를 버리거나 말거나 해서 이탈하는 손님의 최소 수를 구해서 N에서 빼주면 남는 최대 손님수를 알 수 있지 않을까?
// 걍 남는 최대 손님수를 바로 구해볼래.. 하나라도 선호도가 5이상인 음식이 있으면 남는거니까
int f(int jdx, bool check, int cnt) {
    
    if(jdx > N && cnt == K) return 0;
    if(K < cnt) return -INF;
    
    int& ret = cache[jdx][check][cnt];
    if(ret != -1) return ret;
    ret = -INF;
    
    // j번메뉴를 버려도 선호도5이상인 메뉴가 있으면
    if(check) {
        for(int i=1; i<=N; i++) { // 버리면
            arr[i][jdx] = 0;
        }
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(arr[i][j] >= 5) {
                    flag = true; check = true;
                    break;
                }
                else {
                    flag = false; check = false;
                }
            }
            if(flag) leave++;
        }
        if (!check) return -INF;
        
        ret = max(ret, f(jdx + 1, check, cnt + 1) + leave); //남은 손님수 최대 구하기
    }

    return ret;
}
int main() {
    memset(cache, -1, sizeof(cache));
    cin >> M >> K;
    for (int i=1; i<=N; i++) { // i번 손님의 j번 메뉴 선호도 입력받기
        for (int j=1; j<=M; j++) {
            cin >> arr[i][j];
            ans[i][j] = arr[i][j];
        }
    }
    
    cout << f(1, true, 0);
    return 0;
}

//int f(int jdx, bool check, int cnt) {
//
//    if(jdx > N && cnt == K) return 0;
//    if(K < cnt) return -INF;
//
//    int& ret = cache[jdx][check][cnt];
//    if(ret != -1) return ret;
//    ret = INF;
//
//    // j번메뉴를 버려도 선호도5이상인 메뉴가 있으면
//    if(check) {
//        for(int i=1; i<=N; i++) { // 버리면
//            arr[i][jdx] = 0;
//        }
//        for(int i=1; i<=N; i++) {
//            for(int j=1; j<=M; j++) {
//                if(arr[i][j] >= 5) {
//                    flag = true; check = true;
//                    break;
//                }
//                else {
//                    flag = false; check = false;
//                }
//            }
//            if(!flag) leave++;
//        }
//        if (!check) return -INF;
//
//        ret = min(f(jdx + 1, check, cnt), f(jdx + 1, check, cnt + 1) + leave); //이탈한 손님수 최소 구해보기.
//    }
//
//    return ret;
//}
