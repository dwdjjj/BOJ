#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

map<string, int> m;
vector<string> v;
int N, M;

bool cmp(const string a, const string b){
    if(m[a]!=m[b]) return m[a]>m[b];
    else {
        if(a.length()!=b.length()) return a.length()>b.length();
        else return a<b;
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        if(s.length() < M) continue;
        if(m.find(s)==m.end()){
//            m.insert({s,0});
            m[s] = 0;
            v.push_back(s);
        }
        m[s]++;
    }
    sort(v.begin(), v.end(), cmp);
    
    for(string &s:v)cout << s << "\n";
    return 0;
}
