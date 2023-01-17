#include <vector>
#include <iostream>
using namespace std;
int n;
vector<pair<int, int>> v; // index, 갈 위치 가리키는 수

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(make_pair(i, x));
    }
    
    while (!v.empty()) {
        
        cout << v.front().first + 1 << " ";
        int d = v.front().second;
        v.erase(v.begin());
        
        if (v.empty()) break;
        
        if (d < 0) {
            for (int i=0; i<(-d); i++) { // 맨뒤 원소를 맨앞에 넣고 맨뒤에 있는애 지움
                v.insert(v.begin(), v.back());
                v.erase(v.end()-1);
            }
        }
        else {
            for (int i=0; i<d-1; i++) { // 맨앞 원소를 맨뒤에 하나 더넣고 원래 맨앞에 있던애 지움
                v.push_back(v.front());
                v.erase(v.begin());
            }
        }
    }
    
    return 0;
}

