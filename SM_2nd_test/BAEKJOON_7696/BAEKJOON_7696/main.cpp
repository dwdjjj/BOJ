#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
// n번째 반복 숫자 없는 수 ex) 11, 22는 반복숫자이므로 적지 않고 1, 2, 3, ... 26, 27 => 27이 25번째 반복숫자없는 수이다.
// 반복숫자는 11, 22, 33, 44, ... 99, 111, 112, 113, ... 211, 222, 233 ... 인데.. 아무리봐도 string이 편할듯한데
// 시간초과뜨니 숫자로 다시 ㄲ
int arr[1000000+2];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, d, x, cur = 1, y = 1;
    int digit[10+2];
    bool flag = false;
    while (y < 1000000+2) { //100만까지 반복숫자처리 미리해두기
        x = cur;            //1부터 시작해 반복숫자가 있다면 수만 더해주고
        for (int i=0; i<10; i++) {
            digit[i] = 0;
        }
        flag = false;
        while (0 < x) {
            d = x % 10;
            if (digit[d] == 0) {
                digit[d]++;
                x /= 10;
            }
            else {
                flag = true;
                break;
            }
        }
        if (!flag) {
            arr[y] = cur;
            y++;
        }
        cur++;
    }
    while(1) {
        cin >> n;
        if (n == 0) break;
        else cout << arr[n] << "\n";
    }
    return 0;
}
