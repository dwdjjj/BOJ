#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector<vector<string>>v;
    vector<string>strv;
    v.clear();
    strv.clear();
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        strv.push_back(str);
        v.push_back(strv);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << v[i][j] << "\n";
        }
    }
    return 0;
}
