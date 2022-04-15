#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<char>v;
dfs인가 bfs인가 뭔가 하는 그런거냐 ㅡㅡ 몰라
int cnt = 0;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    string S;
    cin >> S;
    for(int i=0; i<S.size(); i++){
        v.push_back(S[i]);
    }
    sort(v.begin(), v.end());
    while(1){
        bool flag = true;
        for(int i=0; i<v.size()-1; i++){
            if(v[i]==v[i+1]){
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
    return 0;
}
