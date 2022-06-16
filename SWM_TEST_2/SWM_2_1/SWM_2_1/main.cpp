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
int cache[MAX_N][2][MAX_M];
int N, M, K; // N손님, M현재메뉴개수, K없애려는 메뉴 개수
// j번 메뉴를 버릴지 말지 정해서 이탈하는 손님 제외 나머지가 남음
// 선호도가 5이상인 메뉴가 최소 1개는 있는지 확인하고 (j번메뉴를 버려도 5이상인 메뉴가 전부 사라지는지 아닌지 체크)
// 총 K개의 메뉴를 버리고 유지할 수 있는 손님의 최대수 구하기

// 즉, j번메뉴를 버리거나 말거나 해서 이탈하는 손님의 최소 수를 구해보자.
int f(int jdx, bool check, int cnt) {
    int leave = 0;
    bool flag = true;
    if(jdx > N && cnt == K) return 0;
    if(K < cnt) return -INF;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(arr[i][j] >= 5) {
                check = true;
                break;
            }
            else check = false;
        }
    }
    if(!check) return -INF;
    
    
    int& ret = cache[jdx][check][cnt];
    if(ret != -1) return ret;
    ret = INF;
    
    // j번메뉴를 버려도 선호도5이상인 메뉴가 있으면
    if(check) {
        for(int i=1; i<=N; i++) { // 버리면
            arr[i][jdx] = 0;
        }
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(arr[i][j] >= 5) {
                    flag = true;
                    break;
                }
                else flag = false;
            }
            if(!flag) leave++;
        }
        ret = min(f(jdx + 1, check, cnt), f(jdx + 1, check, cnt + 1) + leave); //이탈한 손님수를 세는 게 나을듯
    }


    return ret;
}
int main() {
    memset(cache, -1, sizeof(cache));
    cin >> M >> K;
    for (int i=1; i<=N; i++) { // i번 손님의 j번 메뉴 선호도 입력받기
        for (int j=1; j<=M; j++) {
            cin >> arr[i][j];
        }
    }
    cout << f(1, true, 0);
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>
using namespace std;
const int MAX_N = 100000+4;
int arr[MAX_N]; // 조사만족도 배열
vector<int> v[MAX_N]; // 친구사이저장
int N, M, K;
// i번 수강생이 설문을 했으면 만족도를 저장하고, 안했으면 친구를 찾아서 친구들의 만족도 평균을 내서 저장하고 N명의 수강생의 만족도의 평균 구하기

int main() {
    memset(arr, -1, sizeof(arr));
    cin >> N >> M >> K;
    for (int i=0; i<M; i++) {
        int x, s; cin >> x >> s;
        arr[x] = s;
    }
    for (int i=0; i<K; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }

    for(int i=1; i<=N; i++) {
        int sum = 0;
        if(arr[i] == -1) {
            
        }
    }

    return 0;
}
