#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n, m; // n개 짜장면, m개 웍[각 웍마다 크기 입력받음]
int cache[10000+3];
vector<int> s;
vector<int> v;
vector<bool> visited(n+3, false);
//int f(int x) {
//
//}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x; cin >> x;
        s.push_back(x);
        visited[s[i]] = true;
    }
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            v.push_back(s[i] + s[j]);
        }
    }
    
    sort(v.begin(), v.end());
    
//    for (int i=1; i<s.size()-1; i++) {
//        for (int j=i+1; j<s.size(); j++) {
//            int tmp = s[i] + s[j];
//            if(tmp <= n && !visited[tmp]) {
//                visited[tmp] = true;
//                s.push_back(tmp);
//            }
//        }
//    }
//
//    vector<int> dp(n+1, 0);
//    for (int i=0; i<s.size(); i++) {
//        dp[s[i]] = 1;
//        for (int j=s[i] + 1; j<=n; j++) {
//            if (!dp[j - s[i]]) continue;
//            if (!dp[j] || dp[j] > dp[j-s[i]]+1) dp[j] = dp[j-s[i]]+1;
//        }
//    }
//
//    if (!dp[n]) cout << -1;
//    else cout << dp[n];
    return 0;
}


// 1, 3, 5
// 1,3,4(1+3),5,6(1+5),8(3+5) / 2(1+1), 7(3+4), 9(8+1), 10(4+6), 12(8+4)

// 1, 3
// 1, 3, 4 / 2, 5, 6, 7, 8 /
//
//static int func(int dishes){
//        if(dishes==0) return 0;
//        else if(dishes<0) return INF;
//
//        if(dp[dishes] != 0) return dp[dishes];
//
//        int result = INF;
//        for(int k : dogu){
//            result = Math.min(result, func(dishes-k)+1);
//        }
//
//        dp[dishes] = result;
//        return dp[dishes];
//    }
