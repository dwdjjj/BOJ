#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;
    string num;
    int sum = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ',') {
            sum += stoi(num);
            num = "";
        }
        else num.push_back(s[i]);
    }
    cout << sum + stoi(num);
    return 0;
}
