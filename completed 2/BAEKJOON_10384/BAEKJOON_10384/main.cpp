#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    cin.ignore();
    
    for(int i=1; i<=n; i++){
        string s;
        
        getline(cin, s);
        
//        vector<int> visited(26, 0);
        int visited[26] = {0, };
        for(int j=0; j<s.size(); j++){
            if('A' <= s[j] && s[j] <= 'Z') visited[s[j] - 'A']++;
            if('a' <= s[j] && s[j] <= 'z') visited[s[j] - 'a']++;
        }
//        sort(visited.begin(), visited.end());
        sort(visited, visited+26);
        
        string ans;
        cout << "Case " << i;
        if(visited[0] == 3) cout << ": Triple pangram!!!\n";
        else if(visited[0] == 2) cout << ": Double pangram!!\n";
        else if(visited[0] == 1) cout << ": Pangram!\n";
        else cout << ": Not a pangram\n";
        
    }
    
    return 0;
}
