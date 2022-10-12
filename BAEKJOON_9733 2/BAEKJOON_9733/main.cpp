#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#define pair pair<string, int>
using namespace std;
//unordered_map<string, int> mp;
map<string, int> mp;
vector<string> Bee = {"Re","Pt","Cc","Ea","Tb","Cm","Ex"};
double total = 0;
string s;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
//    while (getline(cin, s)) {
//        stringstream ss(s);
//        while (ss >> s) {
//            mp[s]++;
//            total += 1;
//        }
//    }
    for (int i=0; i<24; i++) {
        string s; cin >> s;
        mp[s]++;
        total += 1;
    }
    
    for (int i=0; i<Bee.size(); i++) {
        string tmp = Bee[i];
        if (mp.find(tmp) != mp.end()) {
            cout << tmp << ' ' << mp[tmp] << ' '
            << fixed << setprecision(2) << mp[tmp]/total << '\n';
        }
        else cout << tmp << ' ' << 0 <<  " 0.00\n";
    }
    cout << "Total " << total << " 1.00";
    
    return 0;
}
