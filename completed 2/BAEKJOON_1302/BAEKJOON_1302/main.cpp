#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, cnt;
map<string, int>m;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cin >> N;
    
    while(N--) {
        string name;
        cin >> name;
        m[name]++;
    }
    
    for(auto i = m.begin(); i!= m.end(); i++) {
        cnt = max(cnt, i->second);
    }
    for(auto i : m){
        if(i.second==cnt){
            cout << i.first;
            return 0;
        }
    }
    return 0;
}
