//소마 코테 1번 : 키워드 n개의 키워드가 있을 때 t개의 입력문자열에 따라 포함되는 키워드 문자열의 개수 구하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, t;
vector<string> v;
int main() {
    cin >> n;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    cin >> t;
    for (int i=0; i<t; i++) {
        string tmp; cin >> tmp;
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (v[j].length() < tmp.length()) continue;
            if (v[j].length() == tmp.length()) {
                if (v[j] == tmp) cnt++;
            }
            else {
                int len = tmp.length();
                for(int k=0; k<v[j].length()-len+1; k++){
                    bool flag = true;
                    for(int l = 0; l<len; l++) {
                        if(tmp[l] == v[j][l+k]) {
                            continue;
                        }
                        else {
                            flag = false;
                            continue;
                        }
                    }
                    if(flag) {
                        cnt++; break;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
