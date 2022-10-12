// 4번 : 식단짜기
// 1번,2번,3번으로 식단을 짰다면 3번,2번,1번으로 짜는건 포함 x
// 2000이상 2500이하 칼로리로 식단을 짤 수 있는 가짓수 구해주기
// 예제 입력 : 4
//          300 500 800 1000
// 예제 출력 : 2
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
const int INF = 987654321;
using namespace std;
int n;
vector<int> v;
int cache[8003][2503][4];


// 조건 만족하는 식단의 가짓수구해야함
// idx번째의 식단을 먹을지 말지 정해서 sum을 원하는 칼로리 범위내로 하도록하는 가짓수 구하는 함수
// 식단 개수 (cnt) 세개까지
int f(int idx, int sum, int cnt) {
    if (cnt == 3) {
        return (2000 <= sum && sum <= 2500 ? 1 : 0);
    }
    if (idx >= n) {
        return 0;
    }

    int& ret = cache[idx][sum][cnt];
    if(ret != -1) return ret;

    return ret += f(idx + 1, sum, cnt) + f(idx + 1, sum + v[idx], cnt + 1);

}
int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    cout << f(0, 0, 0);
    return 0;
}
