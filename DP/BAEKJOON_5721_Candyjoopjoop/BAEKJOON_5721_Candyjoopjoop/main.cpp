
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 987654321;
int m, n;
vector<vector<int>> v;
vector<vector<vector<int>>> cache;
// 박스 고른 바로 윗행, 아래행, 왼쪽하나 오른쪽하나 모두 사라짐.
// 상태공간 정의 : 고른 행에서 최대한 많은 사탕을 가져가야 함. m개의 행 중 가장 사탕을 많이 가져갈 수 있는 행을 고르고 (아래아래 행에서 마찬가지로 사탕을 가장 많이 가져갈 수 있도록 선택)
// flag는 이번 y행에서 사탕상자를 한번이라도 먹었는지. 먹었다면 바로 이웃한 사탕상자 못고름
// ㅡㅡㅡㅡㅡㅡㅡㅡ
// 반복문이 쉬울듯
int arr[100000];
int tmp[100000];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        cin >> m >> n;
        if (m == 0 && n == 0) return 0;
        
        cache.assign(m+3, vector<vector<int>>(n+3,vector<int>(2, -1)));
        v.resize(m+3, vector<int>(n+3, 0));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> v[i][j];
            }
            for (int j=1; j<n; j++) {
                if (j == 1) {
                    <#statements#>
                }
            }
        }
        cout << f(0, 0, 0) << "\n";
    }
    
    
    return 0;
}
