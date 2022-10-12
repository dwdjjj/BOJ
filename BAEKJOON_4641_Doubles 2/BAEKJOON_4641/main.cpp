#include <vector>
#include <iostream>
using namespace std;
vector<int> v;

int main(int argc, const char * argv[]) {
    while(1) {
        int x; cin >> x;
        if (x == -1) break;
        
        int cnt = 0;
        if (x == 0) {
            for (int i=0; i<v.size(); i++) {
    //            cout << v[i] << " ";
                for (int j=0; j<v.size(); j++) {
                    if (v[i] == v[j] * 2) {
                        cnt++;
                    }
                }
            }
            cout << cnt << "\n";
            v.clear();
        }
        else v.push_back(x);
    }
    return 0;
}
