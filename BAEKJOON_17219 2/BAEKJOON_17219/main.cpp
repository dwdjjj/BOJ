#include <map>
#include <iostream>
using namespace std;
int N, M;
map<string, string>m;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    cin.tie(0);
    cin >> N; cin >> M;
    while(N--){
        string address, password;
        cin >> address >> password;
        m.insert({address, password});
    }
    while(M--){
        string a;
        cin >> a;
        cout << m[a] << '\n';
    }
    return 0;
}
