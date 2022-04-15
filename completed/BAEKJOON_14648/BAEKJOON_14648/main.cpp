#include <iostream>
#include <vector>
using namespace std;
int v[1003];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){ // 수열 입력받기
        cin >> v[i];
    }
    for(int i=0; i<q; i++){ // q개 쿼리 출력하기
        int kind, a, b, c, d, tmp;
        long long sum = 0, tmpA = 0, tmpB = 0;
        cin >> kind;
        if(kind == 1) {
            cin >> a >> b;
            for(int i=a; i<=b; i++){
                sum += v[i];
            }
            tmp = v[a];
            v[a] = v[b];
            v[b] = tmp;
        }
        if(kind == 2) {
            cin >> a >> b >> c >> d;
            for(int i=a; i<=b; i++){
                tmpA += v[i];
            }
            for(int i=c; i<=d; i++){
                tmpB += v[i];
            }
            sum = tmpA - tmpB;
        }
        cout << sum << "\n";
    }
    return 0;
}
