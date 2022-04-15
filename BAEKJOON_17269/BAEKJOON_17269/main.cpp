#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m, ans;
int arr[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
vector<int> v;
vector<int> tmp;
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    int len = max(int(s1.size()), int(s2.size()));
    
    for (int i=0; i<len; i++) {
        if (i < s1.size()) v.push_back(arr[s1[i] - 'A']);
        if (i < s2.size()) v.push_back(arr[s2[i] - 'A']);
    }
    while (1) {
        for (int i=0; i<v.size()-1; i++) {
            int x = v[i] + v[i+1];
//            if(x < 10) res[i] = x;
            tmp.push_back(x % 10);
        }
        v.clear();
        for (int i=0; i<tmp.size(); i++) {
            v.push_back(tmp[i]);
        }
        if (tmp.size() == 2) {
            break;
        }
        else tmp.clear();
    }
    cout << v[0]*10 + v[1] << "%";
    return 0;
}
