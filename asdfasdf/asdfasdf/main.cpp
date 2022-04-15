#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
map<string, int>mp;
vector<string> v;
int N, M;

/* bool cmp(const string &a, const string &b){
    if(a.length()==b.length()&&mp[a]==mp[b]) return a<b;
    else if(mp[a]==mp[b]) return a.length()>b.length();
    else return mp[a]>mp[b];
}*/

bool cmp(const string a, const string b){
    if(mp[a]!=mp[b]) return mp[a]>mp[b];
    else{ // 나온 횟수 같을 때
        if(a.length()!=b.length()) return a.length()>b.length();
        else return a<b;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N;i++){
        string s;
        cin >> s;
        if(s.length()<M) continue; // 짧은 길이의 단어는 스킵
        if(mp.find(s)==mp.end()){ // if(m.find("f") == m.end()) -> not found
            mp.insert({s,0});
            v.push_back(s);
        }
        mp[s]++;                  // else -> found
    }
    sort(v.begin(), v.end(), cmp);
    for(auto &s:v)cout << s << "\n";
    return 0;
}
