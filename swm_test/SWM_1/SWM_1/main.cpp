#include <iostream> //4번
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
const int INF = 987654321;
using namespace std;
int n;
vector<int> v;
int cache[8003][2503];
// 조건 만족하는 식단의 가짓수구해야함
// idx번째의 식단을 먹을지 말지 정해서 sum을 원하는 칼로리 범위내로 하도록하는 가짓수 구하는 함수
int f(int idx, int sum) {
    
    if(idx >= n) {
        return -INF;
    }

    int& ret = cache[idx][sum];
    if(ret != -1) return ret;
    if(idx < n && 2000 <= sum && sum <= 2500) {
        return ret;
    }

    if(sum < 2000) {
        ret = max(ret, f(idx+1, sum + v[idx]) + 1);
    }

    return ret;
}
int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    cout << f(0, 0);
    return 0;
}

#include <iostream> //5 3분값
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int a, b, n;
vector<int> v;
int main() {
    cin >> a >> b;
    v.push_back(a); v.push_back(b);
    cin >> n;
    for(int i=0; i<n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back(x); v.push_back(y); v.push_back(z);
        sort(v.begin(), v.end());
        int tmp = (v.size() - 2)/3;
        cout << v[tmp] << " " << v[1 + tmp*2];
        cout << "\n";
    }
    
    // 5개면 3*1 + 2개 있을 때고, 두번째 네번째 출력 == 1, 3
    // 1 2 4 5 7
    // 8개면 3*2 + 2개 있을 때고, 3, 6번째 출력 == 2, 5
    // 1 2 3 4 5 6 7 8
    // 11개면? 3*3 + 2개 있을 때, 4, 8번째 출력 == 3, 7
    // 3*4 + 2 = 14 => 1234 5 6789 10 11121314
    return 0;
}

#include <iostream>
#include <vector> //. 1키워드
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


#include <iostream>
#include <string> // 3 복호화
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int a, b;
vector<char> ans;
vector<int> res;
int main() {
    cin >> a >> b;
    string s;
    cin >> s;
    // a = 0, b =1, ... z= 25
    // g = 6,u, o, e = 4
    // for (int i=0; i<s.length(); i++) {
    //     int tmp = s[i]- 'a';
    //     int tmp2 = (tmp - b) / a;
    //     ans.push_back(tmp2 + 'a');
    // }
    for(int i=0; i<s.length(); i++) {
        for(int j=0; j<26; j++) {
            if((j*a + b)%26 == s[i] - 'a') {
                ans.push_back(j + 'a');
                break;
          }
        }
    }
    // for(int i=0; i<res.size(); i++) {
    //     cout << res[i];
    // }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}
