#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_LEN = 40+4;
string s1, s2;
string dp[MAX_LEN][MAX_LEN];

// LCS (Longest Common Substring) : 두 문자열을 한글자씩 비교하면서 이차원 배열에 수를 기록.
// 문자가 같을때 해당 칸 LCS[i-1][j-1]에 1 더해줌.
// Longest Common Subsequence : 위랑 비슷하되 두 문자가 다르면 LCS[i-1][j]와 LCS[i][j-1]중 큰 값 표시.

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s1 >> s2;
    
    for (int i=0; i<s1.length(); i++) {
        for (int j=0; j<s2.length(); j++) {
            auto& tmp = dp[i+1][j+1] = dp[i][j];
            if (s1[i] == s2[j]) tmp += s1[i];
            else  tmp = (dp[i][j+1].length() > dp[i+1][j].length()) ? dp[i][j] = dp[i][j+1] : dp[i][j] = dp[i+1][j];
        }
    }
    cout << dp[s1.length()][s2.length()];
    return 0;
}
