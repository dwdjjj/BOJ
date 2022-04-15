#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<string, int>>v;

bool compare(pair<string, int>a, pair<string, int>b){
    
    if(a.first.length()!=b.first.length()) return a.first.length()<b.first.length();
    else {
        if(a.second!=b.second) return a.second<b.second;
        else return a<b;
    }

}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    // v.clear();
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        // v[i].first = s;
        
        int sum = 0;
        for(int j=0; j<s.size(); j++){
            if('0'<=s[j]&&s[j]<='9') sum += s[j]-'0';
        }
        // v[i] = make_pair(s, sum); 아니 왜 메이크페어랑 퍼스트세컨드에 넣는건 안되고 푸쉬백만되는데;
        v.push_back({ s, sum });
        // v[i].second = sum;
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<n; i++){
        cout << v[i].first <<"\n";
    }
    return 0;
}
